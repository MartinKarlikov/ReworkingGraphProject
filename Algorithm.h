#pragma once
#include <iostream>
#include <string>
class Vertex;
class Edge;
class Graph;
using namespace std;

class Algorithm
{

public:

	void execute(const string& startId, const string& endId) const;

protected:

	virtual void doExecute(const string& startId,const string& endId) const = 0;

	virtual bool checkPathValidity(const string & startId, const string & endId) const;

	const Graph* graph;
};