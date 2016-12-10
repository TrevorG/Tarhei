cmake_minimum_required(VERSION 2.6)
project(Tarhei)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(COMPILE_OPTIONS 
	-std=c++14 
	-Werror 
	-Wpedantic 
	-Wall 
	-Wextra 
	-Wfloat-equal 
	-Wmissing-include-dirs 
	-Wundef 
	-Wshadow 
	-Wcast-qual 
	-Wcast-align 
	-Wsign-conversion 
	-Wconversion 
	-Wuseless-cast 
	-Wlogical-op 
	-Wredundant-decls 
	-Wformat=2 
	-Wformat-signedness 
	-Wsuggest-final-types 
	-Wsuggest-final-methods 
	-Wsuggest-override)

set(LIB_HEADERS
	include/Packet.h
	include/Port.h)
add_custom_target(includes SOURCES ${LIB_HEADERS})

include_directories(include)
file(GLOB LIB_SOURCES src/*.cpp)
add_library(Tarhei SHARED ${LIB_SOURCES})
target_compile_options(Tarhei PUBLIC ${COMPILE_OPTIONS})

set(PLAYGROUND_SOURCES examples/playground.cpp)
link_directories(${LIBRARY_OUTPUT_PATH})
add_executable(playground ${PLAYGROUND_SOURCES})
target_link_libraries(playground Tarhei)
target_compile_options(playground PUBLIC ${COMPILE_OPTIONS})
