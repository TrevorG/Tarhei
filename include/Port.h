#pragma once

#include <Packet.h>
#include <PortBase.h>
#include <PortHandlerBase.h>

#include <utility>

namespace Tarhei {

template <typename PortHandlerType>
class Port : public PortBase
{
public:
	Port(PortHandlerType h); //no reference, because we are copying this anyway

	PortHandlerType& getHandler() override;

private:
	PortHandlerType handler;
};

template <typename PortHandlerType>
Port<PortHandlerType>::Port(PortHandlerType h)
	: handler(h)
{}

template <typename PortHandlerType>
PortHandlerType& Port<PortHandlerType>::getHandler()
{
	//TODO: add static_assert for deriving from PortHAndlerBase
	return handler;
}

template <typename PortHandlerType, typename... Args>
Port<PortHandlerType> make_port(Args&&... args)
{
	return Port<PortHandlerType>(PortHandlerType(std::forward<Args>(args)...));
}

} /* namespace Tarhei */
