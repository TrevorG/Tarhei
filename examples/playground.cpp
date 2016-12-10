#include <Packet.h>
#include <Port.h>

#include <iostream>
#include <string>

using namespace Tarhei;
using namespace std;

class CoutDumperPort
{
public:
	void handle(const Packet<string>& p)
	{
		std::cout << "Received string packet: " << p.get_data() << std::endl;
	}
};

int main(int, char **)
{
	auto packet = make_packet<string>("Test_packet");
	auto port = make_port<CoutDumperPort>();

	port.receive(packet);

	return 0;
}
