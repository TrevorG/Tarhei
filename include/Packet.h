#pragma once

#include <utility>

namespace Tarhei {

template <typename PacketDataType>
class Packet
{
public:
	Packet(PacketDataType d); //no reference, because we are copying this anyway

	const PacketDataType& get_data() const;

private:
	PacketDataType data;
};

template <typename DataType>
Packet<DataType>::Packet(DataType d)
	: data(d)
{}

template <typename DataType>
const DataType& Packet<DataType>::get_data() const
{
	return data;
}

template <typename DataType, typename... Args>
Packet<DataType> make_packet(Args&&... args)
{
	return Packet<DataType>(DataType(std::forward<Args>(args)...));
}

}
