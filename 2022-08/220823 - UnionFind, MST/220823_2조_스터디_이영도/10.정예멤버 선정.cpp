#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std;

int A[3][3] = {
	2, 6, 3,
	7, 1, 1,
	3, 4, 2
}, B[2][4] = {
	6, 4, 2, 4,
	1, 1, 5, 8
}, C[2][3] = {
	9, 2, 3,
	4, 2, 1
}, map[3][3];

int main() {
	int max, maxY, maxX;
	int min, minY, minX;

	for(int t = 0; t < 3; t++){ // A 배열 
		max = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (max < A[i][j]) {
					max = A[i][j];
					maxY = i;
					maxX = j;
				}
			}
		}
		map[0][t] = A[maxY][maxX];
		A[maxY][maxX] = 0;
	}


	for (int t = 0; t < 3; t++) { // B 배열
		min = 99;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 4; j++) {
				if (min > B[i][j]) {
					min = B[i][j];
					minY = i;
					minX = j;
				}
			}
		}
		map[1][t] = B[minY][minX];
		B[minY][minX] = 99;
	}

	for (int t = 0; t < 3; t++) { // C 배열
		max = 0;
		min = 99;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				if (min > C[i][j]) {
					min = C[i][j];
					minY = i;
					minX = j;
				}
				if (max < C[i][j]) {
					max = C[i][j];
					maxY = i;
					maxX = j;
				}
			}
		}
		if (t == 0) {
			map[2][0] = C[minY][minX];
			C[minY][minX] = 8;
		}
		if (t == 1) {
			map[2][1] = C[minY][minX];
			C[minY][minX] = 8;
		}
		if (t == 2) {
			map[2][2] = C[maxY][maxX];
		}
	}

	for (int i = 0; i < 3; i++) { // 출력
		for (int j = 0; j < 3; j++) {
			cout << map[i][j] << " ";
		} cout << endl;
	}

	return 0;
}