#pragma once

#include <Packet.h>
#include <Component.h>
#include <Handlers.h>

#include <utility>

namespace Tarhei {

class Port
{
public:
	Port(Component& owner_);

	void link(Port&);

	template <typename PacketDataType>
	void receive(Packet<PacketDataType>&& packet);

	template <typename PacketDataType>
	void send(Packet<PacketDataType>&&);

private:
	Component& owner;
	Port *linkedPort;
};

template <typename PacketDataType>
void Port::receive(Packet<PacketDataType>&& packet)
{
	//TODO: this is some kind of hack. It needs performace measurements and
	//some improvements (maybe even rework)
	auto handler = dynamic_cast<detail::SingleHandler<PacketDataType> *>(&owner);
	if(handler)
	{
		handler->handle(*this, std::move(packet));
	}
	else
	{
		//FIXME: log about default handle method
	}
}

template <typename PacketDataType>
void Port::send(Packet<PacketDataType>&& p)
{
	if(linkedPort)
	{
		linkedPort->receive(std::move(p));
	}
	else
	{
		//TODO: some log about not linked port? Error maybe?
	}
}

} /* namespace Tarhei */
