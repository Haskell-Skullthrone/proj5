#include<iostream>
class BitMatrixGraph {
protected:
	unsigned char** bitAdjacencyMatrix;
	int n; //number of nodes in the graph
public:
	BitMatrixGraph();
	BitMatrixGraph(int numNodes);
	BitMatrixGraph(const BitMatrixGraph& otherGraph);
	friend std::ostream& operator<<(std::ostream&s,BitMatrixGraph&g);
	//overloaded = operator
	void addEdge (int u, int v);
	bool isAnEdge (int u, int v);
	//other that you want and will be useful
	void BitMatrixGraph::printBits();
};