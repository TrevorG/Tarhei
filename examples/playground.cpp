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
	void handle(Packet<string>& p) override
	{
		std::cout << "Received string packet: " << p.getData() << std::endl;
	}

	void handle(Packet<int>& p) override
	{
		std::cout << "Received int packet: " << p.getData() << std::endl;
	}
};

class DummyComponent :
	public Component
{

};

int main(int, char **)
{
	CoutDumper receiver;
	DummyComponent sender;

	Port sender_outport(sender);
	Port receiver_inport(receiver);

	auto packet_string = make_packet<string>("Test_packet");
	auto packet_int = make_packet<int>(43);

	std::cout << "Should not emit anything:" << std::endl;
	sender_outport.send(packet_string);
	sender_outport.link(receiver_inport);
	std::cout << "Should emit something:" << std::endl;
	sender_outport.send(packet_string);
	sender_outport.send(packet_int);

	return 0;
}
