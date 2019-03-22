#include "Dijkstra.h"
#include "Graph.h"
#include <limits.h>

void Dijkstra::printRoute(unordered_map<string,const Vertex*> prev, const string& curr) const
{
	
	const Vertex* prevVert = prev[curr];

	if (!prevVert)
	{
		cout << curr << " ";
		return;
	}

	printRoute(prev, prevVert->getID());

	cout << curr << " ";

}

const string Dijkstra::getMinVert(const vector<string>& notVisited, unordered_map<string, size_t>& weights) const
{
	string min = notVisited.front();
	
	vector<string>::const_iterator graphIt = notVisited.begin();

	for (; graphIt != notVisited.end(); ++graphIt)
	{
		const string& curr = (*graphIt);
		if (weights[curr] < weights[min])
		{
			min = curr;
		}
	}

	return min;
}

void Dijkstra::updateAdj(const string& curr,
	const vector<string>& notVisited,
	unordered_map<string,const Vertex*>& prev,
	unordered_map<string, size_t>& weights) const
{

	const Vertex& current = graph->getVert(curr);

	Graph adjacent = current.getAdjacent();

	Graph::GraphIterator adjIt = adjacent.getIterator();

	for (; !adjIt.reachedEnd(); ++adjIt)
	{
		size_t& currAdjWeight = weights[(*adjIt).getID()];

		if (find(notVisited.begin(),notVisited.end(),(*adjIt).getID()) != notVisited.end())
		{
			size_t alt = weights[curr] + current.getEdgeWeight((*adjIt));

			if (alt < currAdjWeight)
			{
				currAdjWeight = alt;
				prev[(*adjIt).getID()] = &current;
			}

		}
	}
}

Dijkstra::Dijkstra(const Graph * const graph)
{
	this->graph = graph;
}

void Dijkstra::doExecute(const string& startId,const string& endId) const
{


	vector<string> notVisited;
	unordered_map<string, size_t> weights;
	unordered_map<string,const Vertex*> prev;

	Graph::GraphIterator graphIt = graph->getIterator();

	for (; !graphIt.reachedEnd(); ++graphIt)
	{
		const string& currID = (*graphIt).getID();
		notVisited.push_back(currID);
		weights[currID] = UINT32_MAX;
		prev[currID] = nullptr;
	}

	weights[startId] = 0;


	while (!notVisited.empty())
	{

		const string min = getMinVert(notVisited,weights);

		if (min == endId)
		{
			
			cout << "The price of the route is: " << weights[min] << endl;
			
			printRoute(prev,min);

			cout << endl;

			return;

		}

		notVisited.erase(find(notVisited.begin(),notVisited.end(),min));

		updateAdj(min,notVisited,prev,weights);

	}

}
