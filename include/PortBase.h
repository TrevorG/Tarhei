#pragma once

#include <Handler.h>
#include <PortHandlerBase.h>

namespace Tarhei {

class PortBase
{
public:
	template <typename PacketDataType>
	void receive(Packet<PacketDataType>& packet);

	virtual PortHandlerBase& getHandler() = 0;

	virtual ~PortBase()
	{}
};

template <typename PacketDataType>
void PortBase::receive(Packet<PacketDataType>& packet)
{
	//TODO: this is some kind of hack. It needs performace measurements and
	//some improvements (maybe even rework)
	auto handler = dynamic_cast<Handler<PacketDataType> *>(&getHandler());
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

}
