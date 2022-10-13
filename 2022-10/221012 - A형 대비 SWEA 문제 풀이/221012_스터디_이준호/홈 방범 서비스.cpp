#include <iostream>
#include <queue>
using namespace std;

int N, M, K, ans;
int map[20][20];
int used[20][20];
int cntHome;
int ditY[4] = { -1,1,0,0 };
int ditX[4] = { 0,0,-1,1 };

struct Node {
	int y, x, lev;
};
queue<Node> q;

void init() {
	ans = -1;
	cntHome = 0;
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 20; x++) {
			map[y][x] = 0;
		}
	}
}

void input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] == 1) cntHome++;
		}
	}
}

int findLimitK() {
	K = 0;
	int temp = 0;
	int suik = cntHome * M;
	while (1) {
		temp = K * K + (K - 1) * (K - 1);
		if (suik - temp < 0) break;
		K++;
	}
	return K;
}

void initused() {
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 20; x++) {
			used[y][x] = 0;
		}
	}
}

int fp(int yy, int xx, int sum) {
	q.push({ yy,xx,0 });
	used[yy][xx] = 2;
	if (map[yy][xx] == 1) sum++;

	while (!q.empty()) {
		
		Node now = q.front();
		q.pop();
		if (now.lev == K - 1) break;

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ditY[i];
			int nx = now.x + ditX[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (used[ny][nx] == 2) continue;
			used[ny][nx] = 2;
			if (map[ny][nx] == 1) sum++;
			q.push({ ny,nx, now.lev + 1 });
		}
	}
	if (sum * M - (K * K + (K - 1) * (K - 1)) >= 0) return sum;
	else return -1;
	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;

	for (int tc = 1; tc <= tcCnt; tc++) {
		init();
		input();
		K = findLimitK();
		if (cntHome == 1) { ans = 1; break; }

		while (K > 0) {
			if (K == 1) { ans = 1; break; }
			for (int y = 0; y < N; y++) {
				for (int x = 0; x < N; x++) {
					while (!q.empty()) {
						q.pop();
					}
					initused();
					ans = max(ans, fp(y, x, 0));
				}
			}
			if (ans > 0) break;
			K--;
		}
		
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}