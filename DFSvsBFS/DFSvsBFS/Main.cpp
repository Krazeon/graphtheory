/*
Authors: Hunter Nguyen, Tou Vang, Micah Weltzin
*/

#include <iostream>;
#include <vector>;

using namespace std;

int main() 
{

}

class Graph
{

};

class Vertex
{
	string m_Name;
	int m_Degree;
	vector<Vertex> m_AdjVertices;

	Vertex(string name, int degree, vector<Vertex> adjVertices)
	{
		m_Name = name;
		m_Degree = degree;
		m_AdjVertices = adjVertices;
	}
};

class Edge
{
	string name;
	int weight;
	Vertex v1;
	Vertex v2;
	vector<Edge> edges;
};