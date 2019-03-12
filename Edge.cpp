#include "Edge.h"
#include "Vertex.h"

Edge::Edge()
{
	start = end = nullptr;
	weight = 0;
}

Edge::Edge(Vertex* const start, Vertex* const end, const size_t weight)
{
	this->start = start;
	this->end = end;
	this->weight = weight;
}

Edge::Edge(const Edge & other)
{
	copyEdge(other);
}

Edge & Edge::operator=(const Edge & other)
{
	copyEdge(other);
	return *this;
}

bool Edge::operator==(const Edge & other) const
{
	return start->getID() == other.start->getID()
		&& end->getID() == other.end->getID()
		&& this->weight == other.weight;
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
	return *start;
}

Vertex& Edge::getEnd() const
{
	return *end;
}

const size_t Edge::getWeight() const
{
	return weight;
}

void Edge::copyEdge(const Edge& other)
{
	this->start = other.start;
	this->end = other.end;
	this->weight = other.weight;
}
