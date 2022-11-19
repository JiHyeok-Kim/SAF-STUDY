#include <iostream>
#include <vector>
#include <algorithm>
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

bool cmp(Node t, Node v) {
	if (t.y != v.y) return t.y < v.y;
	if (t.x != v.x) return t.x < v.x;
	return t.cnt > v.cnt;
}

void hap() {
	vector<Node> tmpTong;
	tmpTong.push_back(tong[0]);
	int idx = 0;
	for (int i = 1; i < tong.size(); i++) {
		if (tong[idx].y == tong[i].y && tong[idx].x == tong[i].x) {
			tmpTong.back().cnt += tong[i].cnt;
		}
		else {
			idx = i;
			tmpTong.push_back(tong[idx]);
		}
	}
	tong = tmpTong;
}

void solve() {
	for (int i = 0; i < T; i++) {
		move_turn();
		sort(tong.begin(), tong.end(), cmp);
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