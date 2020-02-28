

#include "Graph.h"
#include <set>		// a class in the C++ STL

// Dijkstra's algorithm - search shortest path for weighted graphs
// when finish, distance[v] will hold the shortest distance from start_vertex to vertex v
void dijkstras_algorithm(Graph& graph, int start_vertex, int* backtrack, double* distance)
{
	int num_v = graph.get_num_v();

	// initialisation
	// all unprocessed vertices v except start_vertex in set v_s 
	//   with corresponding distance and parent from start_vertex to v
	// set - containers store unique elements, always sorted
	set<int> v_s;
	for (int n = 0; n < num_v; n++) {
		if (n != start_vertex) v_s.insert(n);
	}

	distance[start_vertex] = 0.;				// zero distance to start_vertex itself
	for (set<int>::iterator itr = v_s.begin(); itr != v_s.end(); itr++) {
		int v = *itr;
		double w = graph.get_edge(start_vertex, v).get_weight();
		distance[v] = (w > 0.) ? w : DBL_MAX;	// maximum positive double value
		backtrack[v] = start_vertex;
	}
	backtrack[start_vertex] = -1;

	// search - for all vertices v in v_s
	while (!v_s.empty()) {
		// find the vertex u in v_s with the smallest distance[u]
		double min_distance = DBL_MAX;
		int u = -1;
		for (set<int>::iterator itr = v_s.begin(); itr != v_s.end(); itr++) {
			int v = *itr;
			if (distance[v] < min_distance) {
				min_distance = distance[v];
				u = v;
			}
		}
		if (u < 0) break;

		// remove u from set v_s
		v_s.erase(u);

		// for all vertices v in v_s that are adjacent to u
		for (set<int>::iterator itr = v_s.begin(); itr != v_s.end(); itr++) {
			int v = *itr;
			if (graph.get_edge(u, v).get_weight() != 0.0) {
				// distance from start_vertex to u then to v
				double d = distance[u] + graph.get_edge(u, v).get_weight();
				// compared to distance from start_vertex to v
				if (d < distance[v]) {
					distance[v] = d;
					backtrack[v] = u;
				}
			}
		}
	}
}

// test Dijkstra's algorithm
int main3()
{
	cout << "Provide a graph definition file name: ";
	char* file_name = new char[FILENAME_LEN];
	cin >> file_name;

	// create the graph
	Graph graph(file_name);

	// search the shortest path to all destinations from start vertex 0
	double* distance = new double[graph.get_num_v()];
	int* backtrack = new int[graph.get_num_v()];
	dijkstras_algorithm(graph, 0, backtrack, distance);

	// show the path & distance for any destination v
	int v;
	cout << "Specifiy destination vertex v: "; cin >> v;
	cout << "The shortest distance from 0 is: " << distance[v] << endl;
	stack<int> path;
	while (backtrack[v] != -1) {
		path.push(v);
		v = backtrack[v];
	}
	cout << "The shortest path from 0 is: 0 ";
	while (!path.empty()) {
		cout << path.top() << " ";
		path.pop();
	}
	cout << endl;

	delete[] distance;
	delete[] backtrack;
	delete[] file_name;

	return 0;
}
