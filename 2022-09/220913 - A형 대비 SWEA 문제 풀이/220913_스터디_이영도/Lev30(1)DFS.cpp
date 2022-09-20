// 인접행렬 그래프 DFS
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
	{0, 0, 1, 1, 0, 1},
	{0, 0, 0, 1, 1, 1},
	{0, 0, 0, 0, 1, 1},
	{0, 0, 0, 0, 0, 0},
	{1, 0, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0}
};
int used[10];
vector<vector<int>> vec(7);

void dfs(int now) {
	cout << now << " ";

	for (int i = 0; i < vec[now].size(); i++) {

		if (used[vec[now][i]] == 1) continue;
		used[vec[now][i]] = 1;
		dfs(vec[now][i]);
	}

}

int main() {
	int K;
	cin >> K;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (map[i][j] == 1) {
				vec[i].push_back(j);
			}
		}
	}

	used[K] = 1;
	dfs(K);
	cout << endl;

	return 0;
}