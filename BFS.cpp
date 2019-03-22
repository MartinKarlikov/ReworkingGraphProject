#include "BFS.h"
#include "Graph.h"
#include "Vertex.h"

BFS::BFS(const Graph * const graph)
{
	this->graph = graph;
}

void BFS::doExecute(const string & startId, const string & endId) const
{

	const Vertex& start = graph->getVert(startId);
	const Vertex& end = graph->getVert(endId);

	Graph currentPath;
	Graph::GraphIterator currentPathIt = currentPath.getIterator();

	vector<Graph> allPaths;

	currentPath.addVertex(start);
	allPaths.push_back(currentPath);

	while (!allPaths.empty())
	{

		currentPath = *(allPaths.begin());

		allPaths.erase(allPaths.begin());

		const Vertex& last = *(currentPathIt.getLast());


		if (last == end)
		{
			for (currentPathIt = currentPathIt.getBegin(); !currentPathIt.reachedEnd(); ++currentPathIt)
			{
				cout << (*currentPathIt).getID() << " ";
			}
			cout << endl;
			return;
		}

		Graph adjacent = last.getAdjacent();
		Graph::GraphIterator adjIt= adjacent.getIterator();

		for (adjIt;  !adjIt.reachedEnd(); ++adjIt)
		{
			if (!currentPath.containsVert((*adjIt)))
			{
				Graph newPath(currentPath);
				newPath.addVertex((*adjIt));
				allPaths.push_back(newPath);
			}
		}
	}
}
