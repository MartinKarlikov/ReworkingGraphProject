#pragma once
#include <string>
#include <fstream>

class Graph;
class GraphImp;
#define EXTENSION ".txt"

using namespace std;

class GraphParser
{
public:

	void loadGraph(const GraphImp& imp) const;
	void saveGraph(const Graph& graphToSave, const string& graphId, bool directed) const;

protected:

	virtual  void DoLoadGraph(const GraphImp& imp) const;
	virtual  void DoSaveGraph(const Graph& graphToSave, const string& graphId, bool directed) const;

};