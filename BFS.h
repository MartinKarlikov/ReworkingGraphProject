#pragma once
#include "Algorithm.h"

class BFS :public Algorithm
{
public:
	BFS(const Graph* const graph);
public:
	void doExecute(const string& startId, const string& endId) const;
};