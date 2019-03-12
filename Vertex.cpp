#include "Vertex.h"
#include <iostream>
#include "Graph.h"
#include "Edge.h"

Vertex::Vertex(const string identifier)
	:identifier(identifier)
{
	edgeIt = edges.begin();
}

Vertex::Vertex(const Vertex & other)
{
	copyVertex(other);
}

Vertex::~Vertex()
{
	edgeIt = edges.begin();

	for (edgeIt; edgeIt != edges.end(); ++edgeIt)
	{
		(*edgeIt).getEnd().remove(*edgeIt);
	}
}

Vertex & Vertex::operator=(const Vertex & other)
{
	copyVertex(other);
	return *this;
}

void Vertex::add(const Edge& other)
{

	if ((edges.empty() || !contains(other))
		&& other.getStart() == *this)
	{
		edges.push_back(other);

	}
}

void Vertex::remove(const Edge& toRemove)
{
	if (contains(toRemove))
	{
		edges.remove(toRemove);
	}
}

const bool Vertex::isAdjacentTo(const Vertex & other) const
{
	edgeIt = edges.begin();

	for (edgeIt; edgeIt != edges.end(); edgeIt++)
	{
		if ((*edgeIt).getEnd() == other)
		{
			return true;
		}
	}

	return false;
}

const bool Vertex::operator==(const Vertex & other) const
{
	return identifier == other.identifier;
}

const bool Vertex::operator!=(const Vertex & other) const
{
	return !(*this == other);
}

const bool Vertex::contains(const Edge & toContain) const
{
	return (find(edges.begin(), edges.end(), toContain) != edges.end());
}

const string& Vertex::getID() const
{
	return identifier;
}

const Graph Vertex::getAdjacent() const
{
	Graph toReturn;

	edgeIt = edges.begin();
	
	for (edgeIt; edgeIt != edges.end(); ++edgeIt)
	{
		toReturn.addVertex((*edgeIt).getEnd());
	}

	return toReturn;
}

void Vertex::copyVertex(const Vertex & other)
{
	identifier = other.identifier;

	edges = other.edges;
}
