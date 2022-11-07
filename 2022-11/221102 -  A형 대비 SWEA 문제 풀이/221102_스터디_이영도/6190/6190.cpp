// 정곤이의 단조 증가하는 수
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N, num[1001], MAX = -1;

bool isValid(int val) { // Valid check function
	string tmp = to_string(val);

	if (tmp.length() == 1) return true;

	for (int i = 1; i < tmp.length(); i++) {
		if (tmp[i - 1] > tmp[i]) return false;
	}
	
	return true;
}

void DFS(int cnt, int start, int val) { // DFS function
	if (cnt == 2) {
		if (isValid(val)) { // isValid func call
			if (MAX < val) MAX = val;
		}

		return;
	}

	for (int i = start; i < N; i++) {
		DFS(cnt + 1, i + 1, val * num[i]);
	}
}

void init() { // initialization function
	N = 0;
	MAX = -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		init(); // init func call
		cin >> N;

		for (int i = 0; i < N; i++) { cin >> num[i]; }

		DFS(0, 0, 1); // DFS func call

		cout << "#" << tc + 1 << " " << MAX << endl;
	}

	return 0;
}
