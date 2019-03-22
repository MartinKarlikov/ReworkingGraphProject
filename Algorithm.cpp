#include "Algorithm.h"
#include "Graph.h"
#include "Vertex.h"

void Algorithm::execute(const string & startId, const string & endId) const
{

	if (checkPathValidity(startId,endId))
	{
		doExecute(startId, endId);
	}
}

bool Algorithm::checkPathValidity(const string & startId, const string & endId) const
{

	Vertex start(startId);

	Vertex end(endId);

	if (!graph->containsVert(start))
	{
		cout << "Not a valid starting point" << endl;
		return false;
	}

	if (!graph->containsVert(end))
	{
		cout << "Not a valid end point" << endl;
		return false;
	}

	return true;
}
