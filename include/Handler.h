#pragma once

#include <Packet.h>

namespace Tarhei
{

template <typename PacketDataType>
class Handler
{
//TODO: add helper static_assert for user to ensure that all methods are overriden
public:
	virtual void handle(const Packet<PacketDataType>&) = 0;
};

}
