#include <Packet.h>
#include <Port.h>
#include <PortHandler.h>

#include <iostream>
#include <string>

using namespace Tarhei;
using namespace std;

class CoutDumperPort : public PortHandler<string, int>
{
public:
	void handle(const Packet<string>& p) override
	{
		std::cout << "Received string packet: " << p.get_data() << std::endl;
	}

	void handle(const Packet<int>& p) override
	{
		std::cout << "Received int packet: " << p.get_data() << std::endl;
	}
};

int main(int, char **)
{
	auto packet_string = make_packet<string>("Test_packet");
	auto packet_int = make_packet<int>(43);
	auto port = make_port<CoutDumperPort>();

	port.receive(packet_string);
	port.receive(packet_int);

	return 0;
}
