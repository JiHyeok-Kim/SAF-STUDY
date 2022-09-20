// 그래프 순회
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> vec(1001);
vector<int> pvec;
int used[1001];

void dfs(int now) {

	cout << now << " ";

	for (int i = vec[now].size() - 1; i >= 0; i--) {
		if (used[vec[now][i]] == 1) continue;
		used[vec[now][i]] = 1;
		dfs(vec[now][i]);
	} pvec.push_back(now);
}

int main() {
	int n, k, s;
	cin >> n >> k >> s;

	for (int i = 0; i < k; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		vec[tmp1].push_back(tmp2);
	}

	for (int i = 0; i <= n; i++) {
		sort(vec[i].begin(), vec[i].end());
	}

	used[s] = 1;
	dfs(s);
	cout << endl;
	for (int i = 0; i < pvec.size(); i++) {
		cout << pvec[i] << " ";
	} cout << endl;

	return 0;
}