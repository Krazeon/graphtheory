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

int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.BFS(2);

	system("pause");

	return 0;
}