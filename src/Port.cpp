#include <Port.h>

namespace Tarhei
{

Port::Port(Component& owner_)
	: owner(owner_)
	, linkedPort(nullptr)
{}

void Port::link(Port& pb)
{
	linkedPort = &pb;
	pb.linkedPort = this;
}

}
