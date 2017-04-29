#include<iostream>
using namespace std;
void printBits (unsigned char s) {
	//print the bit pattern
	for (int i=0; i < 8; i++)
		if (s & (1 << (7-i)))
			cout << 1;
		else
			cout << 0;
}
int main () {
	unsigned char l = 0x01 << 1; // set l to be equal to 2;
	cout << "Printing the bits before changing: ";
	printBits(l);
	cout << endl;
	//set the third bit from right to be a 1
	l |= 0x01 << 2;
	cout << "Printing the bits after setting the third bit from the right to be a 1: ";
	printBits(l);
	cout << endl;
	//set the second bit from the right to be a 0
	l &= ~(0x01 << 1);
	cout << "Printing the bits after setting the second bit from the right to be a 0: ";
	printBits(l);	
	cout << endl;
	//check the second bit from the right
	if (l & (1 << 1))
	cout << "Second bit from right is set" << endl;
	else
	cout << "Second bit from right is not set" << endl;
}