#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>

using namespace std;

const double SPLIT = 0.01;
const int COUNT = 200;
const double PI = 3.14159265;
const int INTERVAL = 300;

int main() {
	DWORD busySpan[COUNT];
	DWORD idleSpan[COUNT];
	int half = INTERVAL / 2;
	double radian = 0.0;
	for (int i = 0; i < COUNT; i++) {
		busySpan[i] = (DWORD)(half + (sin(PI*radian)*half));
		idleSpan[i] = INTERVAL - busySpan[i];
		radian += SPLIT;
	}

	DWORD startTime = 0;
	int j = 0;
	while (true) {
		j %= COUNT;
		startTime = GetTickCount();
		while ((GetTickCount() - startTime) <= busySpan[j]);
		Sleep(idleSpan[j]);
		j++;
	}
	return 0;
}