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

class DummyPort : public PortHandler<>
{

};

int main(int, char **)
{
	CoutDumperPort receiver_port_handler;
	DummyPort sender_port_handler;
	auto packet_string = make_packet<string>("Test_packet");
	auto packet_int = make_packet<int>(43);
	auto sender_port = make_port(sender_port_handler);
	auto receiver_port = make_port(receiver_port_handler);

	std::cout << "Should not emit anything:" << std::endl;
	sender_port.send(packet_string);
	sender_port.link(receiver_port);
	std::cout << "Should emit something:" << std::endl;
	sender_port.send(packet_string);
	sender_port.send(packet_int);

	return 0;
}
