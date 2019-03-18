#include "Vertex.h"
#include "Graph.h"

Vertex::Vertex(const string& identifier)
	:identifier(identifier)
{
	edgeIt = edges.begin();
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

void Vertex::remove(const Vertex & toRemove)
{
	edgeIt = edges.begin();

	while (edgeIt != edges.end())
	{

		if ((*edgeIt).getEnd() == toRemove)
		{

			const Edge& edgeToDel = (*edgeIt);

			++edgeIt;

			edges.remove(edgeToDel);
		}

		else
		{
			++edgeIt;
		}
	}
}

const bool Vertex::isAdjacentTo(const Vertex & other) const
{
	edgeIt = edges.begin();

	for (edgeIt; edgeIt != edges.end(); ++edgeIt)
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

const Edge & Vertex::getEdge(const string& id) const
{
	edgeIt = edges.begin();

	for (edgeIt; edgeIt != edges.end(); ++edgeIt)
	{
		if ((*edgeIt).getEnd().getID() == id)
		{
			return (*edgeIt);
		}
	}
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

const size_t Vertex::getEdgeWeight(const Vertex & other) const
{
	edgeIt = edges.begin();

	for (edgeIt; edgeIt != edges.end(); ++edgeIt)
	{
		if ((*edgeIt).getEnd() == other)
		{
			return (*edgeIt).getWeight();
		}
	}

	return 0;
}

