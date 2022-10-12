#include <iostream>
#include <set>
using namespace std;

struct atom {
	int x;
	int y;
	int dir;
	int E;
	bool state;
};

atom atoms[1001];

int map[2001][2001];
int N;
int atomCnt;

int answer;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,-1,1 };

bool isOpp(int a, int b) {
	int dir1 = atoms[a].dir;
	int dir2 = atoms[b].dir;
	if (dir1 == 0 && dir2 == 1) return true;
	else if (dir1 == 1 && dir2 == 0) return true;
	else if (dir1 == 2 && dir2 == 3) return true;
	else if (dir1 == 3 && dir2 == 2) return true;

	return false;
}

void moveAtom(int idx)
{
	int nx = atoms[idx].x + dx[atoms[idx].dir];
	int ny = atoms[idx].y + dy[atoms[idx].dir];
	if (nx < 0 || ny < 0 || nx > 2000 || ny > 2000) {
		map[atoms[idx].y][atoms[idx].x] = 0;
		atoms[idx].state = false;
		atomCnt--;
		return;
	}
	if (map[ny][nx] != 0 && isOpp(map[ny][nx], idx)) {
		atoms[idx].state = false;
		atoms[map[ny][nx]].state = false;
		atomCnt -= 2;
		answer += atoms[idx].E;
		answer += atoms[map[ny][nx]].E;
		map[atoms[idx].y][atoms[idx].x] = 0;
		map[ny][nx] = 0;
		return;
	}
	map[atoms[idx].y][atoms[idx].x] = 0;
	atoms[idx].y = ny;
	atoms[idx].x = nx;
}

void searchCrush() {
	set<pair<int, int>> crush;

	for (int i = 1; i <= N; i++) {
		if (atoms[i].state == false) continue;
		atom now = atoms[i];
		if (map[now.y][now.x] == 0) {
			map[now.y][now.x] = i;
		}
		else if (map[now.y][now.x] != 0) {
			atomCnt--;
			atoms[i].state = false;
			answer += atoms[i].E;
			crush.insert({ now.y, now.x });
		}
	}
	for (auto loop : crush) {
		int tmp = map[loop.first][loop.second];
		answer += atoms[tmp].E;
		atoms[tmp].state = false;
		atomCnt--;
		map[loop.first][loop.second] = 0;
	}
}

void init() {
	for (int i = 0; i < 2001; i++) {
		for (int j = 0; j < 2001; j++) {
			map[i][j] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> N;
		atomCnt = N;
		answer = 0;

		init();

		for (int i = 1; i <= N; i++) {
			int x, y, d, k;
			cin >> x >> y >> d >> k;
			int curX = x + 1000;
			int curY = y + 1000;
			atoms[i] = { curX,curY,d,k,true };
			map[curY][curX] = i;
		}

		while (atomCnt > 1) {
			for (int i = 1; i <= N; i++) {
				if (atoms[i].state) {
					moveAtom(i);
				}
			}
			searchCrush();
		}

		cout << "#" << t << " " << answer << '\n';
	}
	return 0;
}