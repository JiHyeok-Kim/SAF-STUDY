#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, C, ans;
int map[11][11];
int sumTong[11][11];
int tempTong[5];
int path[5];
struct honey {
	int num, y, x;
};

vector<honey> result;

void init() {
	ans = -21e8;
	for (int y = 0; y < 11; y++) {
		for (int x = 0; x < 11; x++) {
			map[y][x] = 0;
			sumTong[y][x] = 0;
		}
	}
	for (int i = 0; i < 5; i++) {
		tempTong[i] = 0;
		path[i] = 0;
	}

	result.clear();
}
void input() {
	cin >> N >> M >> C;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}
}

void findmaxi(int y, int x) {
	int a = 0;
	for (int i = 0; i < M; i++) {
		if (path[i]) {
			a += tempTong[i] * tempTong[i];
		}
	}

	if (a > sumTong[y][x]) {
		sumTong[y][x] = a;
	}
}

void dfs(int lev, int y, int x) {
	if (lev == M) {
		int sum = 0;
		for (int i = 0; i < M; i++) {
			if (path[i]) {
				sum += tempTong[i];
			}
		}
		if (sum <= C) {
			findmaxi(y,x);
		}

		return;
	}

	for (int i = 0; i < 2; i++) {
		path[lev] = i;
		dfs(lev + 1, y, x);
		path[lev] = 0;
	}

}

bool cmp(honey t, honey v) {
	return t.num > v.num;
}

void getMax() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N - M + 1; x++) {
			result.push_back({sumTong[y][x], y, x});
		}
	}
	sort(result.begin(), result.end(), cmp);
	int de = 1;

	for (int i = 1; i < result.size(); i++) {
		if (result[0].y != result[i].y) {
			ans = result[0].num + result[i].num;
			break;
		}
		else if (abs(result[0].x - result[i].x) >= M) {
			ans = result[0].num + result[i].num;
			break;
		}
	}
}

void solve() {
	// 한통에서 채취할 수 있는 양 sumTong에 입력
	int idx;
	for (int y = 0; y < N; y++) {

		for (int x = 0; x < N - M + 1; x++)
		{
			idx = 0;
			for (int k = x; k < x + M; k++) 
			{
				tempTong[idx] = map[y][k];
				idx++;
			}
			// tempTong에서 만들 수 있는 수익중 최대?
			dfs(0, y, x);
		}
	}
	getMax();
}


int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		init();
		input();
		solve();
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}