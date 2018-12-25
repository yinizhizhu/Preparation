#include <iostream>
#include <stdlib.h>

const unsigned char HEAD = 1 << 7;

using namespace std;

int count1(int v) {
	int counter = 0;
	for (; v;) {
		counter += v & 0x01;
		v >>= 1;
	}
	return counter;
}

int count2(int v) {
	int counter = 0;
	for (; v;) {
		v &= (v - 1);
		counter++;
	}
	return counter;
}

int countTable[256];

void init() {
	for (int i = 0; i < 256; i++)
		countTable[i] = count2(i);
}

int count3(int v) {
	return countTable[v];
}

int main(){
	init();
	int v = rand() % 256;
	cout << count1(v) << endl;
	cout << count2(v) << endl;
	cout << count3(v) << endl;
	return 0;
}