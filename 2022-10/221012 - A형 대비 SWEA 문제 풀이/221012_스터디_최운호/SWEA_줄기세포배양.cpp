#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct cell {
	int y;
	int x;
	int val;
};

struct info {
	int val;
	int wT;
	int lT;
	int state;
};

bool operator<(cell A, cell B) {
	if (A.val < B.val) return true;
	if (A.val > B.val) return false;

	return false;
}

priority_queue<cell> pq;
queue<cell> q;

info map[701][701];
int N, M, K;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void breed() {
	int size = pq.size();

	if (size == 0) return;

	for (int i = 0; i < size; i++) {
		cell now = pq.top();
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (map[ny][nx].state != 0) continue;
			map[ny][nx].state = 1;
			map[ny][nx].val = now.val;
			q.push({ ny,nx,now.val });
		}
	}
}

void run() {
	int size = q.size();

	for (int i = 0; i < size; i++) {
		cell now = q.front();
		q.pop();

		if (map[now.y][now.x].state == 2 && map[now.y][now.x].lT == 0) {
			pq.push({ now.y, now.x, now.val });
		}

		if (map[now.y][now.x].state == 2) map[now.y][now.x].lT++;
		
		if (map[now.y][now.x].state == 1) {
			map[now.y][now.x].wT++;
			if (map[now.y][now.x].wT == map[now.y][now.x].val) map[now.y][now.x].state = 2;

		}

		if (map[now.y][now.x].val == map[now.y][now.x].lT) {
			map[now.y][now.x].state = -1;
			continue;
		}

		q.push(now);
	}
}
void init() {
	for (int i = 0; i < 701; i++) {
		for (int j = 0; j < 701; j++) {
			map[i][j] = { 0,0,0,0 };
		}
	}
}

int main()
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> N >> M >> K;
		int answer = 0;
		init();
		for (int i = 300; i < N + 300; i++) {
			for (int j = 300; j < M + 300; j++) {
				int tmp;
				cin >> tmp;
				if (tmp > 0) {
					map[i][j] = { tmp,0,0,1 };
					q.push({ i,j,tmp });
				}
			}
		}
		
		for (int i = 0; i < K; i++) {
			run();
			breed();
		}

		for (int i = 0; i < 701; i++) {
			for (int j = 0; j < 701; j++) {
				if (map[i][j].state == 1 || map[i][j].state == 2) answer++;
			}
		}

		cout << "#" << t << " " << answer << '\n';
		while (!q.empty()) q.pop();
		while (!pq.empty()) pq.pop();
	}
	return 0;
}