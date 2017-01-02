#pragma once

#include <Handler.h>
#include <PortHandlerBase.h>

namespace Tarhei
{

template <typename ... PacketDataTypes>
class PortHandler : public PortHandlerBase
	, public Handler<PacketDataTypes>...
{
//helper class only
};

}
