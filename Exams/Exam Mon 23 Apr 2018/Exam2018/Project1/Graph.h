#ifndef GRAPH_H
#define GRAPH_H

class Graph
{
public:
	// Constructor - create a graph from a file with the given name
	Graph(char* fname);
	// Destructor
	~Graph();

	// The graph
	int num_v;		// Number of vertices
	bool directed;	// Direction
	double** edges;	// The 2-D adjaceny matrix
};
#endif
