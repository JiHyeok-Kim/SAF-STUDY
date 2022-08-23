#include <iostream>
#include <string>
using namespace std;

int a[3][3] = { 2,6,3,7,1,1,3,4,2 };
int b[2][4] = { 6,4,2,4,1,1,5,8 };
int c[2][3] = { 9,2,3,4,2,1 };
int usedA[3][3];
int usedB[2][4];
int usedC[2][3];
int res[3][3];
int maxY, maxX;
int minY, minX;
int minCY, minCX;

void findamax(int i) {
	int max = -999;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (usedA[y][x] == 0) {
				if (max < a[y][x]) {
					max = a[y][x];
					maxY = y;
					maxX = x;
				}
			}

		}
	}
	res[0][i] = max;
	usedA[maxY][maxX] = 1;
}

void findbmin(int i) {
	int min = 999;
	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < 4; x++) {
			if (usedB[y][x] == 0) {
				if (min > b[y][x]) {
					min = b[y][x];
					minY = y;
					minX = x;
				}
			}
		}
	}

	res[1][i] = min;
	usedB[minY][minX] = 1;
}
void findc(int i) {
	int minC = 999;
	int maxC = -999;
	if (i != 2) {
		for (int y = 0; y < 2; y++) {
			for (int x = 0; x < 3; x++) {
				if (usedC[y][x] == 0) {
					if (minC > c[y][x]) {
						minC = c[y][x];
						minCY = y;
						minCX = x;
					}
				}

			}
		}
		res[2][i] = minC;
		usedC[minCY][minCX] = 1;
	}

	else {
		for (int y = 0; y < 2; y++) {
			for (int x = 0; x < 3; x++) {
				if (maxC < c[y][x]) {
					maxC = c[y][x];
				}
			}
		}
		res[2][i] = maxC;
	}
}

int main() {


	for (int i = 0; i < 3; i++) {
		findamax(i);
		findbmin(i);
		findc(i);
	}
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cout << res[y][x] << " ";
		}
		cout << "\n";
	}
	return 0;
}