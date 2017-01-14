#include <Packet.h>
#include <Port.h>
#include <Component.h>
#include <Handlers.h>

#include <iostream>
#include <string>

using namespace Tarhei;
using namespace std;

class CoutDumper :
	public Component,
	public Handlers<string, int>
{
public:
	void handle(const Port&, Packet<string>& p) override
	{
		std::cout << "Received string packet: " << p.getData() << std::endl;
	}

	void handle(const Port&, Packet<int>& p) override
	{
		std::cout << "Received int packet: " << p.getData() << std::endl;
	}
};

class SourceComponent :
	public Component,
	public Handlers<double>
{
public:
	void handle(const Port&, Packet<double>& p) override
	{
		std::cout << "Source received packet with double value: " << p.getData() << std::endl;
	}
};

int main(int, char **)
{
	CoutDumper receiver;
	SourceComponent sender;

	Port sender_outport(sender);
	Port receiver_inport(receiver);

	auto packet_string = make_packet<string>("Test_packet");
	auto packet_int = make_packet<int>(43);
	auto packet_double = make_packet<double>(13.37);

	std::cout << "Should not emit anything:" << std::endl;
	sender_outport.send(packet_string);
	sender_outport.link(receiver_inport);
	std::cout << "Should emit something:" << std::endl;
	sender_outport.send(packet_string);
	sender_outport.send(packet_int);
	receiver_inport.send(packet_double);

	return 0;
}
