// proj5.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<queue>
#include"BitMatrixGraph.h"
using namespace std;

int main()
{
	BitMatrixGraph g(20);
	cout << "made a graph\n\n";
	g.addEdge(9,1);
	g.printBits();
    return 0;
}

