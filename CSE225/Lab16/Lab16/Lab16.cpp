// Lab16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "graphtype.cpp"
#include<iostream>

using namespace std;

int main()
{
	//graph creation stratrs
	GraphType<char> g;
	g.AddVertex('A');
	g.AddVertex('B');
	g.AddVertex('C');
	g.AddVertex('D');
	g.AddVertex('E');
	g.AddVertex('F');
	g.AddVertex('G');
	g.AddVertex('H');
	g.AddEdge('F', 'H', 1);
	g.AddEdge('H', 'E', 1);
	g.AddEdge('D', 'E', 1);
	g.AddEdge('D', 'G', 1);
	g.AddEdge('G', 'F', 1);
	g.AddEdge('D', 'A', 1);
	g.AddEdge('A', 'D', 1);
	g.AddEdge('A', 'B', 1);
	g.AddEdge('A', 'C', 1);
	g.AddEdge('B', 'A', 1);
	g.AddEdge('C', 'A', 1);
	//Graph creation ends
	cout << g.OutDegree('D') << endl;
	//Found Edge
	if (g.FoundEdge('A', 'D')) {
		cout << "There is an Edge!" << endl;
	}
	else {
		cout << "There is no Edge!" << endl;
	}
	//Found edge for another time
	if (g.FoundEdge('B', 'D')) {
		cout << "There is an Edge!" << endl;
	}
	else {
		cout << "There is no Edge!" << endl;
	}
	//Use DFS
	g.DepthFirstSearch('B', 'E');
	g.DepthFirstSearch('E', 'B');
	//Use BFS
	g.BreadthFirstSearch('B', 'E');
	g.BreadthFirstSearch('E', 'B');
    return 0;
}

