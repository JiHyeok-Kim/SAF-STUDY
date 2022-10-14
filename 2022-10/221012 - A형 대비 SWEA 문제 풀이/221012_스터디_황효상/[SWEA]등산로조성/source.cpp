#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

struct Node {
	int x;
	int y;
};

int T, N, K;
int mountain[9][9];
Node ttop;
int mov[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
bool check[9][9];
int longer = 2;
int bibig;
vector<Node> kda;
void dfs(int x, int y, int cnt) {

	bool checker = 0;
	for (int a = 0; a < 4; ++a) {
		int nx = x + mov[a][0];
		int ny = y + mov[a][1];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if (check[nx][ny] || mountain[nx][ny] >= mountain[x][y]) continue;
		check[nx][ny] = 1;
		dfs(nx, ny, cnt + 1);
		check[nx][ny] = 0;
		if (checker == 0)
			checker = 1;
	}
	if (!checker) {
		if (longer < cnt) {
			longer = cnt;
		}
	}
}

void gogo() {

	for (int a = 0; a < N; ++a) {
		for (int b = 0; b < N; ++b) {
			if (mountain[a][b] == bibig) {
				check[a][b] = 1;
				dfs(a, b, 1);
				check[a][b] = 0;
			}
		}
	}

}
void solve() {
	gogo();

	for (int k = 1; k <= K; ++k) {
		for (int a = 0; a < N; ++a) {
			for (int b = 0; b < N; ++b) {
				if (mountain[a][b] - k >= 0) {
					mountain[a][b] -= k;
					gogo();
					mountain[a][b] += k;
				}
			}
		}
	}

}
void input() {
	cin >> T;

	for (int t = 0; t < T; ++t) {
		cin >> N >> K;
		int max_num = 0;
		for (int a = 0; a < N; ++a) {
			for (int b = 0; b < N; ++b) {
				cin >> mountain[a][b];
				if (max_num < mountain[a][b])
					max_num = mountain[a][b];
			}
		}
		bibig = max_num;
		solve();
		cout << "#"<<t+1<<" "<<longer<<"\n";
		kda.clear();
		longer = 1;
	}
}

int main()
{
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);
	input();
	return 0;

}
