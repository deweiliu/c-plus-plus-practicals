#ifndef GRAPH_H
#define GRAPH_H
#include<string>
#include <iostream>
#include <fstream>
#include <algorithm>	// part of C++ STL
#include <list>		// a class in the C++ STL 
using std::list;
using namespace std;

// one object represents one graph
class Graph
{
public:
	// constructor - create a graph from a given file
	Graph(string fname);
	// destructor
	~Graph();

	// return the number of vertices
	int get_num_v() const { return num_v; }
	// return the edge between source & dest
	double get_edge(int source, int dest) const;

	
private:
	void init_directed(ifstream &fin);
	void init_undirected(ifstream &fin);

	// a graph
	int num_v;
	bool directed;
	double** edges;	// num_v adjacent-edge lists one for each vertex of the graph
						// list - container, constant-time insertion/erase, sequential access only
};
#endif
