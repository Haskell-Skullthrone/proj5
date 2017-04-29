#include<iostream>
#include<queue>
#include "BitMatrixGraph.h"
//constructors
BitMatrixGraph::BitMatrixGraph(){
	n=0;
	bitAdjacencyMatrix=NULL;
}
BitMatrixGraph::BitMatrixGraph(int numNodes){
	n=numNodes;
	unsigned char bitAdjacencyMatrix[numNodes][numNodes/8+1];
	for(int i = 0; i < numNodes; i++){
		for(int j = 0; j < numNodes/8+1; j++){
			bitAdjacencyMatrix[i][j]=0x00<<8;
		}
	}
}
BitMatrixGraph::BitMatrixGraph(const BitMatrixGraph& otherGraph){
	n=otherGraph.n;
	unsigned char bitAdjacencyMatrix[n][n/8+1];
	for(int i = 0; i < n;++i){
		for(int j = 0; j < n/8+1;++j){
			bitAdjacencyMatrix[i][j]=otherGraph.bitAdjacencyMatrix[i][j];
		}
	}
}

//mutator functions for the bitadjacencymatrix
void BitMatrixGraph::addEdge(int u, int v){
	bitAdjacencyMatrix[u][v/8]|=
		v%8==0?0x80:
		v%8==1?0x01:
		v&8==2?0x02:
		v%8==3?0x04:
		v%8==4?0x08:
		v%8==5?0x10:
		v%8==6?0x20:
		0x40;
	bitAdjacencyMatrix[v][u/8]=bitAdjacencyMatrix[u][v/8];
}
bool BitMatrixGraph::isAnEdge(int u, int v){
	return 0x00!=bitAdjacencyMatrix[u][v/8]&&
		v%8==0?0x80:
		v%8==1?0x01:
		v&8==2?0x02:
		v%8==3?0x04:
		v%8==4?0x08:
		v%8==5?0x10:
		v%8==6?0x20:
		0x40;
}

//helpher function for ostream operator to output chars
void printBits (unsigned char s) {
	//print the bit pattern
	for (int i=0; i < 8; i++)
		if (s & (1 << (7-i)))
			std::cout << 1;
		else
			
			std::cout << 0;
}
//raw output function for bitmatrixgraphs
std::ostream& operator<<(std::ostream&s, BitMatrixGraph&g){
	for(int i = 0; i < g.n/8+1;i++){
		for(int j = 0; j < g.n/8+1;j++){
			printBits(g.bitAdjacencyMatrix[i][j]);
			s<<" ";
		}
		s<<'\n';
	}
}

