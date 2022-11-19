#include <iostream>
#include <vector>
using namespace std;

int N, T, K, ans;
int ditY[] = { 0,-1,1,0,0 };
int ditX[] = { 0, 0,0,-1,1 };

struct Node {
	int y, x, cnt, dr;
};
vector<Node> tong;

void input() {
	cin >> N >> T >> K;
	int a, b, c, d;
	for (int i = 0; i < K; i++) {
		cin >> a >> b >> c >> d;
		tong.push_back({ a,b,c,d });
	}
}

void move_turn() {
	for (int i = 0; i < tong.size(); i++) {
		int ny = tong[i].y + ditY[tong[i].dr];
		int nx = tong[i].x + ditX[tong[i].dr];
		if (ny == 0 || nx == 0 || ny == N - 1 || nx == N - 1) {
			if (tong[i].dr % 2 == 1) tong[i].dr += 1;
			else tong[i].dr -= 1;
			tong[i].cnt /= 2;
		}
		tong[i].y = ny;
		tong[i].x = nx;
	}
}


void hap() {
	int cnt[100][100] = { 0 };
	int maxCnt[100][100] = { 0 };
	int direct[100][100] = { 0 };
	for (int i = 0; i < tong.size(); i++) {
		if (tong[i].cnt == 0)continue;
		int row = tong[i].y;
		int col = tong[i].x;
		cnt[row][col] += tong[i].cnt;
		if (maxCnt[row][col] < tong[i].cnt) {
			direct[row][col] = tong[i].dr;
			maxCnt[row][col] = tong[i].cnt;
		}
	}

	vector<Node> tmp;
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			if (cnt[row][col] == 0) continue;
			tmp.push_back({ row,col,cnt[row][col],direct[row][col] });
		}
	}
	tong = tmp; // vector 복사하기  
}



void solve() {
	for (int i = 0; i < T; i++) {
		move_turn();
		hap();
	}
	for (int i = 0; i < tong.size(); i++) {
		ans += tong[i].cnt;
	}
}


int main()
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		tong.clear();
		ans = 0;
		input();
		solve();
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}