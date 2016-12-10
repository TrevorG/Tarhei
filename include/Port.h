#pragma once

#include <Packet.h>

#include <utility>

namespace Tarhei {

template <typename PortHandlerType>
class Port
{
public:
	Port(PortHandlerType h); //no reference, because we are copying this anyway

	template <typename PacketDataType>
	void receive(const Packet<PacketDataType>& packet);

private:
	PortHandlerType handler;
};

template <typename PortHandlerType>
Port<PortHandlerType>::Port(PortHandlerType h)
	: handler(h)
{}

template <typename PortHandlerType>
template <typename PacketDataType>
void Port<PortHandlerType>::receive(const Packet<PacketDataType>& packet)
{
	handler.handle(packet); //TODO: add static_assert?
}

template <typename PortHandlerType, typename... Args>
Port<PortHandlerType> make_port(Args&&... args)
{
	return Port<PortHandlerType>(PortHandlerType(std::forward<Args>(args)...));
}

} /* namespace Tarhei */
