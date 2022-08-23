#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std;

int map[5][4];

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			if (map[i][j] == 1) cnt++;
		}
		if (cnt == 4) {
			for (int j = 0; j < 4; j++) {
				map[i][j] = map[i-1][j];
				map[i-1][j] = 0;
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cout << map[i][j] << " ";
		} cout << endl;
	}

	return 0;
}