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
	void receive(Packet<PacketDataType>& packet);

	template <typename PacketDataType>
	void send(Packet<PacketDataType>&);

private:
	Component& owner;

	Port *linkedPort;
};

Port::Port(Component& owner_)
	: owner(owner_)
	, linkedPort(nullptr)
{}

void Port::link(Port& pb)
{
	linkedPort = &pb;
}

template <typename PacketDataType>
void Port::receive(Packet<PacketDataType>& packet)
{
	//TODO: this is some kind of hack. It needs performace measurements and
	//some improvements (maybe even rework)
	auto handler = dynamic_cast<detail::SingleHandler<PacketDataType> *>(&owner);
	if(handler)
	{
		//TODO: pass *this as argument
		handler->handle(packet);
	}
	else
	{
		//FIXME: log about default handle method
	}
}

template <typename PacketDataType>
void Port::send(Packet<PacketDataType>& p)
{
	if(linkedPort)
	{
		linkedPort->receive(p);
	}
	else
	{
		//TODO: some log about not linked port? Error maybe?
	}
}

} /* namespace Tarhei */
