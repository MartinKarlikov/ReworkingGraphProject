#pragma once
#include <memory>
#include <iostream>
#include "GraphParser.h"
#include "Graph.h"

//class Algorithm;

using namespace std;

class GraphImp
{

public:

	GraphImp(const string& graphId);

	void loadGraph(const string& fileName);

	void addVertex(const string& id) const;
	void addEdge(const string& startId, const string& endId, size_t weight) const;

	void removeVertex(const string& id) const;
	void removeEdge(const string& startId,const string& endId ) const;

	//void executeAlg(const string& algId,const string& startId,const string& endId) const;

	void saveGraph() const;

	void setNewName(const string& name);
	void setDirected(const bool directed);

	const string getName() const;

private:

	virtual void doAddVertex(const string& id) const;

	virtual void doAddEdge(const string& startId,const string& endId,const size_t weight) const;

	//Algorithm* getAlg(string name) const;

	bool isDirected;

	string currentGraphId;

	unique_ptr<Graph> graph;

	//unique_ptr<Algorithm> alg;

	GraphParser parser;

};
