#include <iostream>
using namespace std;
int main () {
	int n = 10;
	int size;
	// Create the bit Adjacency Matrix structure
	if (n%8 == 0)
		size = n/8;
	else
		size = (int) (n/8) + 1;
	unsigned char** bitAdjacencyMatrix;
	bitAdjacencyMatrix = new unsigned char* [n];
	for (int i=0; i < n; i++) {
		bitAdjacencyMatrix[i] = new unsigned char[size];
	}
	//Initialize the bit Adjacency Matrix structure
	for (int i=0; i < n; i++)
		for (int j=0; j < size; j++)
			bitAdjacencyMatrix[i][j] = 0x00 << 8;
}