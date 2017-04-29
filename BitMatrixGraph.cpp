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
	bitAdjacencyMatrix = new unsigned char*[n];
	for(int i = 0; i < n; i++){
		bitAdjacencyMatrix[i] = new unsigned char[n / 8 + 1];
		for (int j = 0; j < numNodes/8+1; j++) {
			bitAdjacencyMatrix[i][j] = 0x00 << 8;
		}
	}
}
BitMatrixGraph::BitMatrixGraph(const BitMatrixGraph& otherGraph){
	n=otherGraph.n;
	bitAdjacencyMatrix = new unsigned char*[n];
	for (int i = 0; i < n; i++) {
		bitAdjacencyMatrix[i] = new unsigned char[n / 8 + 1];
		for (int j = 0; j < n/8+1; j++) {
			bitAdjacencyMatrix[i][j] = otherGraph.bitAdjacencyMatrix[i][j];
		}
	}
}

//mutator functions for the bitadjacencymatrix
void BitMatrixGraph::addEdge(int u, int v){
	bitAdjacencyMatrix[u][v/8]|=
		v%8==0?0x80:
		v%8==1?0x40:
		v%8==2?0x20:
		v%8==3?0x10:
		v%8==4?0x08:
		v%8==5?0x04:
		v%8==6?0x02:
		0x01;
	bitAdjacencyMatrix[v][u/8] =
		u % 8 == 0 ? 0x80 :
		u % 8 == 1 ? 0x40 :
		u % 8 == 2 ? 0x20 :
		u % 8 == 3 ? 0x10 :
		u % 8 == 4 ? 0x08 :
		u % 8 == 5 ? 0x04 :
		u % 8 == 6 ? 0x02 :
		0x01;
}
bool BitMatrixGraph::isAnEdge(int u, int v){
	return 0x00!=bitAdjacencyMatrix[u][v/8]&&
		v%8==0?0x80:
		v%8==1?0x40:
		v%8==2?0x20:
		v%8==3?0x10:
		v%8==4?0x08:
		v%8==5?0x04:
		v%8==6?0x02:
		0x01;
}

//helpher function for ostream operator to output chars
void printChar (unsigned char s) {
	//print the bit pattern
	for (int i=0; i < 8; i++)
		if (s & (1 << (7-i)))
			std::cout << 1;
		else
			
			std::cout << 0;
}
//raw output function for bitmatrixgraphs
void BitMatrixGraph::printBits(){
	for(int i = 0; i < n;i++){
		for(int j = 0; j < n/8+1;j++){
			printChar(bitAdjacencyMatrix[i][j]);
			std::cout<<" ";
		}
		std::cout<<'\n';
	}
}

