#pragma once
#include <string>
#include <vector>
#include "Edge.h"

class Graph;

using namespace std;

class Vertex
{
public:

	Vertex();
	Vertex(const string& identifier);

	void add(const Edge& other);
	void remove(const Edge& toRemove);
	void remove(const Vertex& toRemove);

	const bool isAdjacentTo(const Vertex& other) const;
	const bool operator==(const Vertex& other) const;
	const bool operator!=(const Vertex& other) const;

	const bool contains(const Edge& toContain) const;

	const Edge& getEdge(const string& id) const;
	const string& getID() const;
	const Graph getAdjacent() const;
	const size_t getEdgeWeight(const Vertex& other) const;

private:

	string identifier;

	vector<Edge> edges;

	mutable vector<Edge>::const_iterator edgeIt;

};

