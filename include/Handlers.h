#pragma once

#include <Packet.h>

namespace Tarhei
{

class Port;

namespace detail
{

template <class PacketDataType>
class SingleHandler
{
public:
	virtual void handle(const Port&, Packet<PacketDataType>&) = 0;
};

}

template <class ... PacketDataTypes>
class Handlers : public detail::SingleHandler<PacketDataTypes>...
{
//TODO: add helper static_assert for user to ensure that all methods are overriden
};

}
