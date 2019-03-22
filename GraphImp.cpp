#include "GraphImp.h"
#include "BFS.h"
#include "Dijkstra.h"

GraphImp::GraphImp(const string& graphId)
{
	currentGraphId = graphId;

	graph = make_unique<Graph>();

	loadGraph(graphId);

	alg = unique_ptr<Algorithm>(getAlg("BFS"));

}

void GraphImp::loadGraph(const string& fileName)
{
	if (fileName != currentGraphId)
	{
		setNewName(fileName);
	}
	parser.loadGraph(*this);
}

void GraphImp::addVertex(const string& id) const
{
	doAddVertex(id);
	
}

void GraphImp::addEdge(const string& startId,const string& endId, size_t weight) const
{
	doAddEdge(startId, endId, weight);
}

void GraphImp::removeVertex(const string& id) const
{

	graph->removeVertex(graph->getVert(id));
}

void GraphImp::removeEdge(const string& startId,const string& endId) const
{

	graph->removeEdge(graph->getEdge(startId, endId));

	if (!isDirected)
	{
		graph->removeEdge(graph->getEdge(endId, startId));
	}
}

void GraphImp::executeAlg(const string & algId, const string & startId, const string & endId) const
{
	alg = unique_ptr<Algorithm>(getAlg(algId));
	alg->execute(startId, endId);
	
}

void GraphImp::saveGraph() const
{
	parser.saveGraph((*graph), currentGraphId, isDirected);
}

void GraphImp::setNewName(const string & name)
{
	if (currentGraphId != name)
	{
		parser.saveGraph((*graph), currentGraphId, isDirected);

		currentGraphId = name;

		isDirected = false;
	}
}

void GraphImp::setDirected(bool directed)
{
	if (isDirected != directed)
	{
		parser.saveGraph((*graph), currentGraphId, directed);

		isDirected = directed;
	}
}

const string GraphImp::getName() const
{
	return currentGraphId;
}

void GraphImp::doAddVertex(const string& id) const
{
	Vertex toAdd(id);

	graph->addVertex(toAdd);
}

void GraphImp::doAddEdge(const string& startId,const string& endId,const size_t weight) const
{
	if (!graph->containsVert(Vertex(startId))
		|| !graph->containsVert(Vertex(endId)))
	{
		return;
	}

	const Vertex* start = &(graph->getVert(startId));

	const Vertex* end = &(graph->getVert(endId));

	Edge toAdd(start, end, weight);

	graph->addEdge(toAdd);

	if (!isDirected)
	{
		Edge reverseAdd(end, start, weight);
		graph->addEdge(reverseAdd);
	}
}

Algorithm * GraphImp::getAlg(const string & name) const
{
	if (name == "BFS")
	{
		return new BFS(graph._Myptr());
	}
	if (name == "Dijkstra")
	{
		return new Dijkstra(graph._Myptr());
	}
	
	return new BFS(graph._Myptr());
}

