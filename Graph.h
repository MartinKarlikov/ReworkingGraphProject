#pragma once
#include <fstream>
#include "Vertex.h"

using namespace std;

class Graph
{

public:

	class GraphIterator;

	void addVertex(const Vertex& toAdd);
	void addEdge(const Edge& toAdd);

	void removeVertex(const Vertex& toRemove);
	void removeEdge(const Edge& toRemove);

	const bool containsVert(const Vertex& toContain) const;
	const bool containsEdge(const Edge& toContain) const;


	const Vertex& getVert(const string& id) const;
	const Edge& getEdge(const string& startId, const string& endId) const;
	GraphIterator getIterator() const;
	const size_t getNumOfVert() const;

	class GraphIterator
	{
	public:
		
		GraphIterator();

		GraphIterator(const list<Vertex>& parent);

		const Vertex& operator*() const;

		GraphIterator getBegin() const;
		bool reachedEnd() const;

		GraphIterator& operator++();
		GraphIterator operator++(int);

		GraphIterator& operator--();
		GraphIterator operator--(int);

	private:
		
		GraphIterator(const list<Vertex>* const parent, list<Vertex>::const_iterator it);

		const list<Vertex>* const parent;
		list<Vertex>::const_iterator it;

	};

private:

	list<Vertex> vertices;

};
