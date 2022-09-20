// 네트워크 바이러스
#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> vec(101);
int cp, n, cnt = 0;
int used[101];

void dfs(int now) {
	cnt++;

	for (int i = 0; i < vec[now].size(); i++) {
		if (used[vec[now][i]] == 1) continue;
		used[vec[now][i]] = 1;
		// cnt++;
		dfs(vec[now][i]);
	}
}

int main() {
	cin >> cp >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	used[1] = 1;
	dfs(1);

	cout << cnt - 1 << endl;

	return 0;
}