#pragma once

namespace Tarhei
{

class PortHandlerBase
{
//this class is mostly empty for now and is used only for dynamic_cast in PortBase::receive
public:
	virtual ~PortHandlerBase()
	{}
};

}
