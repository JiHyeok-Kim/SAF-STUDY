// 가중치 인접행렬 DFS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <algorithm>

using namespace std;

int map[6][6] = {
	{0, 0, 1, 0, 2, 0},
	{5, 0, 3, 0, 0, 0},
	{0, 0, 0, 0, 0, 7},
	{2, 0, 0, 0, 8, 0},
	{0, 0, 9, 0, 0, 0},
	{4, 0, 0, 7, 0, 0}
};
vector<vector<int>> vec(7);
int used[7], ret;

void dfs(int now, int tmp) {
	ret += tmp;
	cout << now << " " << ret << endl;

	for (int i = 0; i < vec[now].size(); i++) {

		if (used[vec[now][i]] == 1) continue;
		used[vec[now][i]] = 1;
		dfs(vec[now][i], map[now][vec[now][i]]);
	}
}

int main() {
	int K;
	cin >> K;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (map[i][j] != 0) {
				vec[i].push_back(j);
			}
		}
	}

	used[K] = 1;
	dfs(K, 0);

	return 0;
}