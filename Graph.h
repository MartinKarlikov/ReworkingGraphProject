#pragma once
#include <fstream>
#include "Vertex.h"
#include <memory>
#include <unordered_map>

using namespace std;

class Graph
{

public:

	class GraphIterator;

	Graph();

	Graph(const Graph& other);
	
	Graph& operator=(const Graph& other);

	~Graph();

	Graph(Graph&& other);

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

		GraphIterator(const unordered_map<string, shared_ptr<Vertex>>& parent);

		GraphIterator(const GraphIterator& other);

		GraphIterator& operator=(const GraphIterator& other);

		const Vertex& operator*() const;

		GraphIterator getBegin() const;
		GraphIterator getLast() const;
		bool reachedEnd() const;

		GraphIterator& operator++();
		GraphIterator operator++(int);

		GraphIterator& operator--();
		GraphIterator operator--(int);

	private:

		
		
		GraphIterator(const unordered_map<string, shared_ptr<Vertex>>* const parent, unordered_map<string, shared_ptr<Vertex>>::const_iterator it);

		const unordered_map<string, shared_ptr<Vertex>>* parent;
		unordered_map<string, shared_ptr<Vertex>>::const_iterator it;

	};

private:

	virtual void doAddVertex(const Vertex& toAdd);
	virtual void doAddEdge(const Edge& toAdd);

	unordered_map<string,shared_ptr<Vertex>> vertices;

	static vector<Graph*> graphs;
	vector<Graph*>::const_iterator graphsIt;

};


