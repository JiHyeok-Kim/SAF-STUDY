// 인접행렬 BFS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

int map[11][11];
int used[11];
queue<int> que;

void dfs() {

	while (!que.empty()) {
		int tmp;
		tmp = que.front();
		que.pop();

		if (used[tmp] == 1) continue;
		cout << tmp << " ";
		used[tmp] = 1;
	}

}

int main() {
	int n;

	cin >> n;

	que.push(0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				que.push(j);
			}
		}
	}

	// used[0] = 1;
	dfs();

	return 0;
}