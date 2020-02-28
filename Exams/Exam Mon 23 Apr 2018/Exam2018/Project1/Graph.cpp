#include "Graph.h"
#include <fstream>
#include <iostream>
using namespace std;

Graph::Graph(char* fname)
{
	ifstream fin(fname);
	if (!fin) {
		cout << "Cannot open: " << fname << endl;
		exit(1);
	}

	fin >> num_v;
	char c;
	fin >> c;
	if (c == 'd') directed = true;
	else if (c == 'u') directed = false;

	edges = new double*[num_v];
	if (directed) {
		for (int i = 0; i < num_v; i++) {
			edges[i] = new double[num_v];
			for (int j = 0; j < num_v; j++) edges[i][j] = 0.;
		}
	}
	else {
		for (int i = 0; i < num_v; i++) {
			edges[i] = new double[i + 1];
			for (int j = 0; j < i + 1; j++) edges[i][j] = 0.;
		}
	}

	int source, dest; double weight;
	while (fin >> source >> dest >> weight) {
		if (!directed && dest > source) edges[dest][source] = weight;
		else edges[source][dest] = weight;
	}
	fin.close();
}

Graph::~Graph()
{
	for (int i = 0; i < num_v; i++) delete [] edges[i];
	delete [] edges;
}
