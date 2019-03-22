#pragma once
#include "Algorithm.h"
#include <vector>
#include <unordered_map>


class Dijkstra :public Algorithm
{
public:
	Dijkstra(const Graph* const graph);

private:

	void doExecute(const string& startId,const string& endId) const;

	const string getMinVert(const vector<string>& notVisited, unordered_map<string, size_t>& weights) const;

	void updateAdj(const string& curr, const vector< string>& notVisited, unordered_map<string,const Vertex*>& prev,
		unordered_map<string, size_t>& weights) const;

	void printRoute(unordered_map<string,const Vertex*> prev, const string& curr) const;
};
