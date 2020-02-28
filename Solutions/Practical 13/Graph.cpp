#include "Graph.h"
#include <fstream>
#include <iostream>
using namespace std;

Graph::Graph(char* fname)
{
	// open the file
	ifstream fin(fname);
	if (!fin) {
		cout << "Cannot open: " << fname << endl;
		exit(1);
	}

	// read num_v and direction of the graph from the file
	fin >> num_v;
	char c;
	fin >> c;
	if (c == 'd') directed = true;
	else if (c == 'u') directed = false;

	// allocate memory for the 2-D edges matrix based on the above information
	edges = new double*[num_v];
	if (directed) {	// directed graph - create a square matrix
		for (int i = 0; i < num_v; i++) {
			edges[i] = new double[num_v];
			for (int j = 0; j < num_v; j++) edges[i][j] = 0.;
		}
	}
	else {	// undirected graph - create a lower-triangular matrix
		for (int i = 0; i < num_v; i++) {
			edges[i] = new double[i + 1];
			for (int j = 0; j < i + 1; j++) edges[i][j] = 0.;
		}
	}

	// read the edges
	int source, dest; double weight;
	while (fin >> source >> dest >> weight) {
		if (!directed && dest > source)		// for undirected graph we only save edges[s][d] with d<=s
			edges[dest][source] = weight;	// an edges[s][d] with d>s is the same as edges[d][s] 
		else edges[source][dest] = weight;
	}
	fin.close();
}

Graph::~Graph()
{
	// release the allocated memory for the 2-D edges matrix 
	for (int i = 0; i < num_v; i++) delete [] edges[i];
	delete [] edges;
}

double Graph::get_edge(int source, int dest) const
{
	if (!directed && dest > source)		// for undirected graph we only save edges[s][d] with d<=s
		return edges[dest][source];		// an edges[s][d] with d>s is the same as edges[d][s]]
	return edges[source][dest];
}
