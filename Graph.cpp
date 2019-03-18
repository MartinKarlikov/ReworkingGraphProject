#include "Graph.h"

void Graph::addVertex(const Vertex& toAdd)
{
	if (!containsVert(toAdd))
	{
		vertices.push_back(toAdd);

	}
}

void Graph::addEdge(const Edge& toAdd)
{
	GraphIterator graphIt(vertices);

	while (!graphIt.reachedEnd())
	{

		if (*graphIt == toAdd.getStart())
		{
			const_cast<Vertex&>((*graphIt)).add(toAdd);
		}

		++graphIt;
	}

}

void Graph::removeVertex(const Vertex& toRemove)
{

	if (!containsVert(toRemove))
	{
		return;
	}

	Graph::GraphIterator graphIt(vertices);

	while (!graphIt.reachedEnd())
	{
		const_cast<Vertex&>((*graphIt)).remove(toRemove);

		++graphIt;
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
	GraphIterator graphIt(vertices);

	while (!graphIt.reachedEnd())
	{
		if ((*graphIt).contains(toContain))
		{
			return true;
		}

		++graphIt;
	}

	return false;
}


const Vertex& Graph::getVert(const string& id) const
{

	GraphIterator graphIt(vertices);

	while (!graphIt.reachedEnd())
	{
		if ((*graphIt).getID() == id)
		{
			return (*graphIt);
		}

		++graphIt;
	}

}

const Edge & Graph::getEdge(const string& startId,const string& endId) const
{
	GraphIterator graphIt(vertices);

	while(!graphIt.reachedEnd())
	{
		if ((*graphIt).getID() == startId)
		{
			return (*graphIt).getEdge(endId);
		}

		++graphIt;
	}

}

Graph::GraphIterator Graph::getIterator() const
{
	return GraphIterator(vertices);
}

const size_t Graph::getNumOfVert() const
{
	return vertices.size();
}


Graph::GraphIterator::GraphIterator():parent(nullptr)
{
}

Graph::GraphIterator::GraphIterator(const list<Vertex>& parent):parent(&parent)
{
	it = parent.begin();
}


const Vertex & Graph::GraphIterator::operator*() const
{
	return (*it);
}

Graph::GraphIterator Graph::GraphIterator::getBegin() const
{
	return GraphIterator(parent,it);
}

bool Graph::GraphIterator::reachedEnd() const
{
	return it == parent->end();
}

Graph::GraphIterator& Graph::GraphIterator::operator++()
{
	++it;
	return *this;
}

Graph::GraphIterator Graph::GraphIterator::operator++(int)
{
	GraphIterator toReturn(parent, it);
	++it;
	return toReturn;
}

Graph::GraphIterator& Graph::GraphIterator::operator--()
{
	++it;
	return *this;
}

Graph::GraphIterator Graph::GraphIterator::operator--(int)
{
	GraphIterator toReturn(parent, it);
	++it;
	return toReturn;
}

Graph::GraphIterator::GraphIterator(const list<Vertex>* const parent, list<Vertex>::const_iterator it):parent(parent)
{
	this->it = it;
}


