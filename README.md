## ReworkingGraphProject

This is a repo where files from the reworked project are added. They will be added as soon as they are reworked.
The project was aimed at graph algorithms and data structures. The files that are/will be uploaded are the reworked files only,
but changes in the code will be pointed out along with reasioning about the changes.

# Reworked so far

*Vertex class - 
Basic class and building block. Vertices have unique ID and a list of Edges that connect them to adjacent Vertices.

Changes in the class:
- Used to return a list of vertices
+ Now it returns a graph
The reason can be seen in the general change of representation of the Graph class
Contains a iterator to it's list of edges as a member so that the proccess of traversal can be as abastract as possible.
(Without creating a whole class for that matter.)
Changes to the container will affect only the members of the class. (E.g. the list and it's iterator)

*Edge class
Represented as pointers to the two connecting Vertices and weight of the edge.
Probably the most basic building block so no changes were made, except removing a few redundancies.

*Graph class
A collection of Vertices representing the graph. At the moment that collection is represented by a list.

Changes in the class:
- Used to be implemented with the singleton design pattern as the programme had to have one graph opened at a time.
+ Now it can have more than one instance.
--Reason - This way we have a way to hide as much as we can the container type (a.k.a the list) that is used
for the implementation by giving the chance for subgraphs to be created by different algorithms. For the same reason
a GraphIterator was added so that we don't implement traversal mechanics in the graph - thus separating concerns.
The Graph should only change if the way we keep vertices changes. Traversal is a different concern and is the only reason
for the GraphIterator to change.

*GraphParser class
This class is used to load and save graphs to files. All work that revolves around saving and loading graphs to files
should be delegated to an inastance of this class.

The two functions that actually save/load graphs are made virtual so that if we want to add different behaviour or state
to graphs (be it by representing the with new classes of Edges or Vertices, via inheritance, or more general changes to graphs
or sub-classes of graphs) we can change the way they are saved simply by creating sub-classes of GraphParser.
The reason the functions are hidden and encapsulated in public functions is that we give sub-classes a change to override behaviour
not change the interface, which should stay stable.

*GraphImp class
All work with graphs should be done by an instance of this class. It delegates saving/loading graphs to files to an instance of
GraphParser and runs Algorithms on the graph ( via the Algorithm class, soon to be added) and changes the Graph only by using
the interface of Graph. The functions that let us add Vertex or Edge are made virtual with the same reasoning as seen in GraphParser
