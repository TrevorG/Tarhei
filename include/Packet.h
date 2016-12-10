#pragma once

#include <utility>

namespace Tarhei {

template <typename DataType>
class Packet
{
public:
	Packet(DataType d); //no reference, because we are copying this anyway

	const DataType& get_data() const;

private:
	DataType data;
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
