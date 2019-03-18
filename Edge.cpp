#include "Edge.h"
#include "Vertex.h"

Edge::Edge(const Vertex* const start,const Vertex* const end, const size_t weight):start(start),end(end),weight(weight)
{
}

bool Edge::operator==(const Edge & other) const
{
	return start->getID() == other.start->getID()
		&& end->getID() == other.end->getID();

}

bool Edge::operator!=(const Edge & other) const
{
	return !(*this == other);
}

bool Edge::operator<(const Edge & other) const
{
	return weight<other.weight;
}

bool Edge::operator>(const Edge & other) const
{
	return weight > other.weight;
}

bool Edge::operator<=(const Edge & other) const
{
	return weight <= other.weight;
}

bool Edge::operator>=(const Edge & other) const
{
	return weight >= other.weight;
}

Vertex& Edge::getStart() const
{
	return const_cast<Vertex&>(*start);
}

Vertex& Edge::getEnd() const
{
	return const_cast<Vertex&>(*end);
}

const size_t Edge::getWeight() const
{
	return weight;
}
