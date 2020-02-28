#include "Graph.h"


Graph::Graph(string fname)
{
	edges = 0; // same as edges = NULL;

	// open the graph definition file for input 
		ifstream fin(fname);
	if (!fin) {
		cout << "Can't open file : "<< fname << endl;
		return;
	}

	// read number of vertices from the file
	fin >> num_v;
	// read direction
	char c;
	fin >> c;
	if (c == 'd') {
		directed = true;
		this->init_directed(fin);
	}
	else {
		if (c == 'u') {
			directed = false;
			this->init_undirected(fin);
		}
		else {
			cout << "The format of graph definition file is wrong.\n";
		}
	}

	fin.close();
}

Graph::~Graph()
{
	for (int i = 0; i < num_v; i++) {
		delete[] edges[i];
	}
	delete[]edges;
}

void Graph::init_directed(ifstream& fin)
{
	// allocate the array of the edge lists, one list for one vertex of the graph
	edges = new double*[num_v];
	for (int i = 0; i < num_v; i++) {
		edges[i] = new double[num_v];
		for (int j = 0; j < num_v; j++) {
			edges[i][j] = 0.;
		}
	}


	// read all edges
	int source, dest; double weight;
	while (fin >> source >> dest >> weight) {
		// add to the list of corresponding source vertex
		edges[source][dest] = weight;
	}
}

void Graph::init_undirected(ifstream &fin)
{// allocate the array of the edge lists, one list for one vertex of the graph
	edges = new double*[num_v];
	for (int i = 0; i < num_v; i++) {
		edges[i] = new double[i + 1];
		for (int j = 0; j < i + 1; j++) {
			edges[i][j] = 0.;
		}
	}

	// read all edges
	int source, dest; double weight;
	while (fin >> source >> dest >> weight) {

		//if source>dest, swap them
		if (source > dest) {
			int temp = source;
			source = dest;
			dest = temp;
		}

		// add to the list of corresponding source vertex
		edges[source][dest] = weight;

	}
}


double Graph::get_edge(int source, int dest) const
{
	if (this->directed ==false) {
		if (source > dest) {
			int temp = source;
			source = dest;
			dest = temp;
		}
	}
	
	return edges[source][dest];
}