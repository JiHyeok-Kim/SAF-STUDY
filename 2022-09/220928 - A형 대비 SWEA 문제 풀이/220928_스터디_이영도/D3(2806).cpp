// N-Queen
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

int N, ret, arr[11];

bool isValid(int cur) { // 유효성 검증 함수

	for (int past = 0; past < cur; past++) {
		if (arr[cur] == arr[past] ||
			abs(arr[cur] - arr[past]) == abs(cur - past)) {
			return false;
		}
	}

	return true;
}

void dfs(int cur) { // DFS
	
	if (cur == N) {
		ret++;
		return;
	}

	for (int next = 0; next < N; next++) {
		arr[cur] = next;
		if (isValid(cur)) {
			dfs(cur + 1);
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		ret = 0;
		cin >> N;

		dfs(0);
	
		cout << "#" << tc + 1 << " " << ret << endl;
	}

	return 0;
}