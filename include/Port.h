#pragma once

#include <Packet.h>
#include <PortBase.h>
#include <PortHandlerBase.h>

#include <utility>

namespace Tarhei {

//TODO: consider removing this template parameter
//it seems that we only use it for getHandler() (for now)
template <typename PortHandlerType>
class Port : public PortBase
{
public:
	Port(PortHandlerType& h);

	PortHandlerType& getHandler() override;

	void link(PortBase&);

	template <typename PacketDataType>
	void send(const Packet<PacketDataType>&);

private:
	PortHandlerType& handler;

	PortBase *linkedPort;
};

template <typename PortHandlerType>
Port<PortHandlerType>::Port(PortHandlerType& h)
	: handler(h)
	, linkedPort(nullptr)
{}

template <typename PortHandlerType>
PortHandlerType& Port<PortHandlerType>::getHandler()
{
	//TODO: add static_assert for deriving from PortHAndlerBase
	return handler;
}

template <typename PortHandlerType>
void Port<PortHandlerType>::link(PortBase& pb)
{
	linkedPort = &pb;
}

template <typename PortHandlerType>
template <typename PacketDataType>
void Port<PortHandlerType>::send(const Packet<PacketDataType>& p)
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

template <typename PortHandlerType>
Port<PortHandlerType> make_port(PortHandlerType& handler)
{
	return Port<PortHandlerType>(handler);
}

} /* namespace Tarhei */
