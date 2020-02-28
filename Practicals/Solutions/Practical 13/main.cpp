#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include "Graph.h"
using namespace std;

#define FILENAME_LEN 100

// test Graph class
int main()
{
	cout << "Provide a graph definition file name: ";
	char* file_name = new char[FILENAME_LEN];
	cin >> file_name;

	// create the graph
	Graph graph(file_name);

	// test if the created graph is correct
	int source, dest; char yesno;
	do {
		cout << "Test if there is an edge between two vertices. \nSpecify Source Destination: ";
		cin >> source >> dest;

		// obtain the weight between the two vertices; weight = 0.0 means no direct edge
		double weight = graph.get_edge(source, dest);
		if (weight == 0.0) 
			cout << "No edge" << endl;
		else cout << source << " "
			<< dest << " "
			<< weight << endl;

		cout << "try another? ";
		cin >> yesno;
	} while (yesno == 'y');

	delete[] file_name;
	return 0;
}

vector<int> breadth_first_search(Graph& graph, int start_vertex)
{
	// get the number of vertices of the graph
	int num_v = graph.get_num_v();

	// the variables (see lecture notes for more details of their uses)
	queue<int> queue;	// hold the vertices to visit
	bool* visited = new bool[num_v];	// note the visit status of each vertex
	vector<int> backtrack(num_v, -1);	// for backtrack

	// initialization
	for (int n = 0; n < num_v; n++)	// no vertex has been visited
		visited[n] = false;
	queue.push(start_vertex);		// push the start_vertex tino queue to be first visted
	visited[start_vertex] = true;	// mark it as having been visited

	// visit all vertices in queue
	while (!queue.empty()) {
		// take a source vertex from the queue 
		int source = queue.front();
		queue.pop();
		// for each destination vertex adjacent to source
		for (int dest = 0; dest < num_v; dest++) {
			// dest can't be ajacent to source as there is no edgee
			if (graph.get_edge(source, dest) == 0.) continue;

			if (visited[dest]) continue;	// skip dest vertex if it has been visited
			queue.push(dest);	// push dest vertex into queue to visit next
			visited[dest] = true;	// mark dest vertex as having been visited
			backtrack[dest] = source;	// record the parent of dest
		}
	}
	delete[] visited;

	return backtrack;
}

// test breadth-first search
int main2()
{
	cout << "Provide graph definition file name: ";
	char* file_name = new char[FILENAME_LEN];
	cin >> file_name;

	// create the graph
	Graph graph(file_name);

	// breadth-first search over the graph with start vertex = 0
	vector<int> backtrack = breadth_first_search(graph, 0);

	// use a stack to backtrack the shortest path from vertex 0 to any vertex v
	int v;
	cout << "Specify the destination vertex: "; cin >> v;
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

	delete[] file_name;
	return 0;
}

void dijkstras_algorithm(Graph& graph, int start_vertex, int* backtrack, double* distance)
{
	int num_v = graph.get_num_v();

	// initialisation
	// all unprocessed vertices v except start_vertex in set v_s 
	//   with corresponding distance and parent from start_vertex to v
	set<int> v_s;
	for (int n = 0; n < num_v; n++) {
		if (n != start_vertex) v_s.insert(n);
	}
	distance[start_vertex] = 0.;	// zero distance to start_vertex itself
	for (set<int>::iterator itr = v_s.begin(); itr != v_s.end(); itr++) {
		int v = *itr;
		double w = graph.get_edge(start_vertex, v);
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
			if (graph.get_edge(u, v) != 0.0) {
				// distance from start_vertex to v via u
				double d = distance[u] + graph.get_edge(u, v);
				// compared to distance from start_vertex directly to v
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
	cout << "Specify destination vertex v: "; cin >> v;
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


