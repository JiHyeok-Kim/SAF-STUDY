#include <iostream>
using namespace std;

int arr[20][20], N, K, result;
void input() {
	cin >> N >> K;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> arr[y][x];
		}
	}
}
void init() {
	result = 0;
}
int getSumX(int tar) {
	int cnt = 0, retCnt = 0;
	for (int i = 1; i <= N + 1; i++) {
		if (arr[tar][i] == 1) cnt++;
		if (arr[tar][i] == 0) {
			if (cnt == K) retCnt++;
			cnt = 0;
		}
	}
	return retCnt;
}
int getSumY(int tar) {
	int cnt = 0, retCnt = 0;
	for (int i = 1; i <= N + 1; i++) {
		if (arr[i][tar] == 1) cnt++;
		if (arr[i][tar] == 0) {
			if (cnt == K) retCnt++;
			cnt = 0;
		}
	}
	return retCnt;
}

void solution() {
	for (int i = 1; i <= N; i++) {
		result += getSumX(i);
		result += getSumY(i);
	}
}


void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		init();
		solution();
		cout << "#" << t << " " << result << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}