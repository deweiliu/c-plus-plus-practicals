#include"Graph.h"
#include<vector>
#include<queue>
// breadth-first search, return backtrack vector 
vector<int> breadth_first_search(Graph& graph, int start_vertex)
{
	// number of vertices of the graph
	int num_v = graph.get_num_v();

	// use a queue to store the vertices waiting to visit
	// queue - container, elements are pushed into the "back" of the container and popped from its "front".
	queue<int> queue;
	// mark vertices that have been visited
	bool* visited = new bool[num_v];
	// use a vector for backtracking, all elements initialised to -1
	vector<int> backtrack(num_v, -1);

	// initialization
	for (int n = 0; n < num_v; n++)
		visited[n] = false;
	queue.push(start_vertex);
	visited[start_vertex] = true;

	// visit all vertices in queue
	while (!queue.empty()) {
		// take a vertex 'source' out of queue to visit
		int source = queue.front();
		queue.pop();
		// for each destination vertex adjacent to source
		for (list<Edge>::iterator itr = graph.begin(source); itr != graph.end(source); itr++) {
			int dest = itr->get_dest();

			if (visited[dest]) continue;
			queue.push(dest);
			visited[dest] = true;

			// track the source leading to this dest
			backtrack[dest] = source;
		}
	}
	delete[] visited;

	return backtrack;
}

// test breadth-first search
int main2()
{
	cout << "Provide a graph definition file name: ";
	char* file_name = new char[FILENAME_LEN];
	cin >> file_name;

	// create the graph
	Graph graph(file_name);

	// breadth-first search over the graph with start vertex = 0
	vector<int> backtrack = breadth_first_search(graph, 0);

	// use a stack to backtrack the shortest path from vertex 0 to any vertex v
	// stack - container, last in first out
	int v;
	cout << "Specify destination vertex: "; cin >> v;
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
