// 어디에 단어가 들어갈 수 있을까
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N, K;
int map[16][16], flag;

void dfs(int xnow, int ynow) {
	// if (cnt == K - 1) cout << "1"; // flag = 1;
	// if (cnt > K - 1) cout << "2";  //flag = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][ynow + j] == 1 && map[i][j + 1] == 1) {
				dfs(i, ynow + j);
			}
		}
	}

}

int main() {
	int TestCase, ret;
	cin >> TestCase;

	for (int t = 1; t <= TestCase; t++) {
		ret = 0;
		cin >> N >> K;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		dfs();
	}

	return 0;
}