/*
Authors: Hunter Nguyen, Tou Vang, Micah Weltzin
*/

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph
{
	int v; // Vertices
	list<int> *adj; // Adjacent Vertices
	void DFSPrinter(int v, bool visited[]);

public:
	Graph(int v);
	void addEdge(int v, int w); //Vertice 1, Vertice 2
	void BFS(int s);
	void DFS(int s);
};

Graph::Graph(int v)
{
	this->v = v;
	adj = new list<int>[v];
}

//Need to account for weights
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::BFS(int s)
{
	bool *visitedNodes = new bool[v];
	for (int i = 0; i < v; i++) {
		visitedNodes[i] = false;
	}

	list<int> queue;

	visitedNodes[s] = true;
	queue.push_back(s);

	list<int>::iterator i;

	while (!queue.empty())
	{
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		for (i = adj[s].begin(); i != adj[s].end(); i++)
		{
			if (!visitedNodes[*i])
			{
				visitedNodes[*i] = true;
				queue.push_back(*i);
			}
		}
	}

}

void Graph::DFSPrinter(int v, bool visitedNodes[])
{
	// Mark the current node as visited and print it 
	visitedNodes[v] = true;
	cout << v << " ";

	// Recur for all the vertices adjacent to this vertex 
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visitedNodes[*i])
			DFSPrinter(*i, visitedNodes);
}

void Graph::DFS(int s)
{

}

void createGraphs()
{
	Graph a(4);
	a.addEdge(0, 1);
	a.addEdge(0, 2);
	a.addEdge(1, 2);
	a.addEdge(2, 0);
	a.addEdge(2, 3);
	a.addEdge(3, 3);

	
}

int main()
{

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.BFS(2);

	system("pause");

	return 0;
}