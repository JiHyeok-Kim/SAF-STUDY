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

int N, ret;
int arr[11];

bool isValid(int cnt) {
	for (int i = 0; i < cnt; i++) {
		if (arr[cnt] == arr[i] ||
			abs(arr[cnt] - arr[i]) == abs(cnt - i)) {
			return false;
		}
	}
	return true;
}

void dfs(int cnt) {
	if (cnt == N) {
		ret++;
		return;
	}

	for (int i = 0; i < N; i++) {
		arr[cnt] = i;
		if (isValid(cnt)) {
			dfs(cnt + 1);
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