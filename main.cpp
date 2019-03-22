#include "GraphImp.h"
#include <iostream>


int main()
{
	GraphImp a("testGraph");

	a.executeAlg("Dijkstra", "Chicago", "Sofia");
}