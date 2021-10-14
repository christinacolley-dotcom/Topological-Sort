# Topological-Sort
This assignment objective was to use previous knowledge of graphs to implement a graph data structure for a topological sort of a directed acyclic graph. A directed acyclic graph is a graph without any directed cycles. The first part of this assignment contained an implementation of the graph class and queue data structure so that the input file can be utilized to construct a graph. The three methods that needed implementation were the buildGraph function, size() function that returns the number of vertices in the graph, displayGraph which prints the graph, and Vertex<T> at which returns the given vertex. The purpose of this first part is to read data from a file to create a graph data structure and display it. These graphs are assumed as unweighted, and adjacency lists are used to store the connection between the nodes.
For part two of the assignment we implement a topological sort algorithm to sort the graph, and output a vector of the vertices in topological order. For topological sorting it is more efficient to use a queue as opposed to a stack for several reasons. The main reason is because of the first in and first out approach that the queue data structure follows is the same approach as the BFS (breadth first search). Using a queue data structure is ideal for this situation.
