#pragma once

class Vertex;

class Edge
{
public:

	Edge(const Vertex* const start,const Vertex* const end,const size_t weight);

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

	const Vertex* start;
	
	const Vertex* end;
	
	size_t weight;
};
