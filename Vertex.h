#pragma once
#include <string>
#include <list>

using namespace std;

class Graph;

class Edge;

class Vertex
{
public:

	Vertex(const string identifier);
	Vertex(const Vertex& other);

	~Vertex();

	Vertex& operator=(const Vertex& other);

	void add(const Edge& other);
	void remove(const Edge& toRemove);

	const bool isAdjacentTo(const Vertex& other) const;
	const bool operator==(const Vertex& other) const;
	const bool operator!=(const Vertex& other) const;

	const bool contains(const Edge& toContain) const;

	const string& getID() const;
	const Graph getAdjacent() const;

private:

	void copyVertex(const Vertex& other);

	string identifier;

	list<Edge> edges;

	mutable list<Edge>::const_iterator edgeIt;

};

