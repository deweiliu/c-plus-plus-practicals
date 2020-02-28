#ifndef GRAPH_H
#define GRAPH_H

class Graph
{
public:
	// constructor - create a graph from a file with the given name
	Graph(char* fname);
	// destructor
	~Graph();

	// return the number of vertices
	int get_num_v() const { return num_v; }
	// return the weight between the given source & dest vertices
	// weight = 0.0 means no edge
	double get_edge(int source, int dest) const;

private:
	// the graph
	int num_v;		// number of vertices
	bool directed;	// direction
	double** edges;	// 2-D adjacency matrix holding weighets for edges 
					// from num_v vertices to num_v vertices
};
#endif
