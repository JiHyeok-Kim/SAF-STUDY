#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std;

char map[6][6];
int datY[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int datX[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
	int a[3], b[3];

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			map[i][j] = '_';
		}
	}

	for (int i = 0; i < 3; i++) {
		cin >> a[i] >> b[i];
		map[a[i] + 1][b[i] + 1] = '#';
	}

	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < 8; i++) {
			map[a[k] + datY[i] + 1][b[k] + datX[i] + 1] = '@';
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << map[i+1][j+1];
		} cout << endl;
	}

	return 0;
}