#include "Graph.h"


vector<Graph*> Graph::graphs;

Graph::Graph()
{
	graphs.push_back(this);
}

Graph::Graph(const Graph & other)
{
	vertices = other.vertices;
	graphs.push_back(this);
}

Graph & Graph::operator=(const Graph & other)
{
	vertices = other.vertices;

	return *this;
}

Graph::~Graph()
{
	graphs.erase(find(graphs.begin(), graphs.end(), this));
}

Graph::Graph(Graph && other)
{
	vertices = move(other.vertices);
	other.vertices.clear();
	graphs.push_back(this);
}

void Graph::addVertex(const Vertex& toAdd)
{
	if (!containsVert(Vertex(toAdd)))
	{
		doAddVertex(toAdd);
	}
}

void Graph::addEdge(const Edge& toAdd)
{
	if (containsVert(toAdd.getStart()))
	{
		doAddEdge(toAdd);
	}

}

void Graph::removeVertex(const Vertex& toRemove)
{

	if (!containsVert(toRemove))
	{
		return;
	}

	vertices[toRemove.getID()].reset();

	vertices.erase(toRemove.getID());

}

void Graph::removeEdge(const Edge& toRemove)
{

	toRemove.getStart().remove(toRemove);

}

const bool Graph::containsVert(const Vertex& toContain) const
{
	return vertices.find(toContain.getID()) != vertices.end();
}

const bool Graph::containsEdge(const Edge & toContain) const
{

	if (containsVert(toContain.getStart()))
	{
		return (*vertices.find(toContain.getStart().getID())).second->contains(toContain);
	}

	return false;
}


const Vertex& Graph::getVert(const string& id) const
{

	return (*(*vertices.find(id)).second);

}

const Edge & Graph::getEdge(const string& startId, const string& endId) const
{
	return (*vertices.find(startId)).second->getEdge(endId);
}

Graph::GraphIterator Graph::getIterator() const
{
	return GraphIterator(vertices);
}

const size_t Graph::getNumOfVert() const
{
	return vertices.size();
}

void Graph::doAddVertex(const Vertex & toAdd)
{
	graphsIt = graphs.begin();

	while (graphsIt != graphs.end())
	{
		if ((*graphsIt)->containsVert(toAdd))
		{
			vertices[toAdd.getID()] = (*graphsIt)->vertices[toAdd.getID()];
			return;
		}
		++graphsIt;
	}

	vertices[toAdd.getID()] = make_shared<Vertex>(toAdd);
}

void Graph::doAddEdge(const Edge & toAdd)
{
	vertices[toAdd.getStart().getID()]->add(toAdd);
}


Graph::GraphIterator::GraphIterator() :parent(nullptr)
{
}

Graph::GraphIterator::GraphIterator(const unordered_map<string, shared_ptr<Vertex>>& parent) : parent(&parent)
{
	it = parent.begin();
}

Graph::GraphIterator::GraphIterator(const GraphIterator & other):parent(other.parent)
{
	it = other.it;
}

Graph::GraphIterator & Graph::GraphIterator::operator=(const GraphIterator & other)
{
	parent = other.parent;
	it = other.it;

	return *this;
}


const Vertex & Graph::GraphIterator::operator*() const
{
	return (*(*it).second);
}

Graph::GraphIterator Graph::GraphIterator::getBegin() const
{
	return GraphIterator(parent, parent->begin());
}

Graph::GraphIterator Graph::GraphIterator::getLast() const
{
	return GraphIterator(parent, --parent->end());
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


Graph::GraphIterator::GraphIterator(const unordered_map<string, shared_ptr<Vertex>>* const parent, unordered_map<string, shared_ptr<Vertex>>::const_iterator it) :parent(parent)
{
	this->it = it;
}


