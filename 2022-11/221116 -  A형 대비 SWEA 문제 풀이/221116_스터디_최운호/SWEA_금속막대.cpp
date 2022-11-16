#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;


struct Node {
	int m;
	int f;
};

int N, maxVal;
vector<Node> v;
vector<int> result;
vector<int> arr[20];
int used[20];

void solve(int lev, int prev, int val, vector<int> temp) {
	if (lev > 0) {
		if (maxVal < val) {
			maxVal = val;
			result = temp;
		}
	}

	for (int i = 0; i < arr[prev].size(); i++) {
		int next = arr[prev][i];
		if (used[next] == 1) continue;
		used[next] = 1;
		temp.push_back(next);
		solve(lev + 1, next, val + 1, temp);
		temp.pop_back();
		used[next] = 0;
	}
}

void init() {
	maxVal = 0;
	cin >> N;

	v.clear();
	result.clear();
	for (int i = 0; i < 20; i++) arr[i].clear();
	

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	int memo[20] = { 0 };

	for (int i = 0; i < N; i++) {
		int stand = v[i].f;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (stand == v[j].m) arr[i].push_back(j);
		}
	}

	vector<int> tmp;
	for (int i = 0; i < N; i++) {
		tmp.push_back(i);
		used[i] = 1;
		solve(1, i, 1, tmp);
		used[i] = 0;
		tmp.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		init();

		cout << "#" << t;
		for (int loop : result) {
			cout << " " << v[loop].m << " " << v[loop].f;
		}
		cout << '\n';
	}
	return 0;
}