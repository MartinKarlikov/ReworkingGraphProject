#pragma once

class Vertex;

class Edge
{
public:

	Edge();

	Edge(Vertex* const start, Vertex* const end,const size_t weight);

	Edge(const Edge& other);

	Edge& operator=(const Edge& other);

	bool operator==(const Edge& other) const;
	bool operator!=(const Edge& other) const;

	bool operator<(const Edge& other) const;
	bool operator>(const Edge& other) const;

	bool operator<=(const Edge& other) const;
	bool operator>=(const Edge& other) const;

	Vertex& getStart() const;
	Vertex& getEnd() const;
	const size_t getWeight() const;

private:

	void copyEdge(const Edge& other);

	Vertex* start;
	
	Vertex* end;
	
	size_t weight;
};