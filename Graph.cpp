#include "Graph.h"
#include "Edge.h"
#include "Vertex.h"

Graph::Graph()
{
	changeIt = vertices.begin();
	traverseIt = vertices.begin();
}

void Graph::addVertex(const Vertex& toAdd)
{
	if (!containsVert(toAdd))
	{
		vertices.push_back(toAdd);

	}
}

void Graph::addEdge(const Edge& toAdd)
{
	changeIt = vertices.begin();

	for (changeIt; changeIt != vertices.end(); ++changeIt)
	{
		if (*changeIt == toAdd.getStart())
		{
			(*changeIt).add(toAdd);
		}
	}
}

void Graph::removeVertex(const Vertex& toRemove)
{

	if (containsVert(toRemove))
	{
		vertices.remove(toRemove);

	}
}

void Graph::removeEdge(const Edge& toRemove)
{
	toRemove.getStart().remove(toRemove);
}

const bool Graph::containsVert(const Vertex& toContain) const
{
	return find(vertices.begin(), vertices.end(), toContain) != vertices.end();
}

const bool Graph::containsEdge(const Edge & toContain) const
{
	traverseIt = vertices.begin();

	for (traverseIt; traverseIt != vertices.end(); ++traverseIt)
	{
		if ((*traverseIt).contains(toContain))
		{
			return true;
		}
	}
	
	return false;
}

void Graph::moveTo(const Vertex & other)
{
	if ((*changeIt).isAdjacentTo(other))
	{
		changeIt = find(vertices.begin(), vertices.end(), other);
	}
}

const Vertex& Graph::getCurrentVert()
{
	return (*changeIt);
}


const size_t Graph::getNumOfVert() const
{
	return vertices.size();
}
