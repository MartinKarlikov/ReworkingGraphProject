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
Also this class is hidden and can only be worked with from the perspective of the Graph class or GraphImp class (not yet reworked)

*Edge class
Represented as pointers to the two connecting Vertices and weight of the edge.
Probably the most basic building block so no changes were made

*Graph class
A collection of Vertices representing the graph. At the moment that collection is represented by a list.

Changes in the class:
- Used to be implemented with the singleton design pattern as the programme had to have one graph opened at a time.
+ Now it can have more than one instance and two iterators were added to the implementation
--Reason - This way we have a way to hide as much as we can the container type (a.k.a the list) that is used
for the implementation and also gives us a way to distinguish between the two different types of operations on the 
graph - traversing or making changes to the graph. It also somewhat gives us concurrency over the two iterators as
one type of operations does not affect the position of the iterator responsible for the other type of operations.
All traversal is implemented by using these two iterators so if a decision is made to change the type of container
the only place changes will be made are in the data members of the class.

+ Also one of the iterators is made mutable so that const operations CAN make changes to it as we make no change to the
graph itself - a.k.a the logical view of our object so the operation is rightfully const
