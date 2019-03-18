#include "GraphParser.h"
#include "Graph.h"
#include "Vertex.h"
#include "GraphImp.h"

void GraphParser::loadGraph(const GraphImp& imp) const
{
	 DoLoadGraph(imp);
}

void GraphParser::saveGraph(const Graph & graphToSave, const string & graphId, bool directed) const
{
	DoSaveGraph(graphToSave, graphId, directed);
}

void GraphParser::DoLoadGraph(const GraphImp& imp) const
{

	ifstream inputFile(imp.getName() + EXTENSION);

	bool directed;

	inputFile >> directed;

	size_t numOfVerts;

	inputFile >> numOfVerts;

	while (numOfVerts > 0)
	{
		string verticeName;
		inputFile >> verticeName;

		imp.addVertex(verticeName);

		string adjcName;
		inputFile >> adjcName;

		while (adjcName != "/" && !inputFile.eof())
		{

			imp.addVertex(adjcName);

			size_t weight;

			inputFile >> weight;

			imp.addEdge(verticeName, adjcName,weight);

			inputFile >> adjcName;
		}

		--numOfVerts;
	}

}

void GraphParser::DoSaveGraph(const Graph& graphToSave,const string& graphId,const bool directed) const
{
	ofstream outputFile(graphId + EXTENSION);

	outputFile << directed << endl;

	outputFile << graphToSave.getNumOfVert() << endl;

	Graph::GraphIterator graphIt = graphToSave.getIterator();

	while (!graphIt.reachedEnd())
	{
		outputFile  << (*graphIt).getID() << " ";

		Graph adjacents = (*graphIt).getAdjacent();

		Graph::GraphIterator adjIt = adjacents.getIterator();

		while (!adjIt.reachedEnd())
		{
			outputFile << (*adjIt).getID() << " " << (*graphIt).getEdgeWeight((*adjIt)) << " ";

			++adjIt;
		}

		outputFile << "/" << endl;

		++graphIt;
	}
}
