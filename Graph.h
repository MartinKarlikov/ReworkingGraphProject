#pragma once
#include <string>
#include <fstream>
#include <list>

using namespace std;

class Edge;

class Vertex;

class Graph
{

public:

	Graph();

	void addVertex(const Vertex& toAdd);
	void addEdge(const Edge& toAdd);

	void removeVertex(const Vertex& toRemove);
	void removeEdge(const Edge& toRemove);

	const bool containsVert(const Vertex& toContain) const;
	const bool containsEdge(const Edge& toContain) const;

	void moveTo(const Vertex& other);

	const Vertex& getCurrentVert();
	

	const size_t getNumOfVert() const;

private:

	list<Vertex> vertices;

	list<Vertex>::iterator changeIt;
	mutable list<Vertex>::const_iterator traverseIt;

};
