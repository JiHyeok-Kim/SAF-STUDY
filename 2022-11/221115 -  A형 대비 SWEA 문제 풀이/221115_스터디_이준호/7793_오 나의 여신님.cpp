#include <iostream>
#include <queue>
#include <string>
using namespace std;

int H, W;
string map[55];
int ditY[] = { -1,1,0,0 };
int ditX[] = { 0,0,-1,1 };

struct Node1 {
	int y, x, cnt;
};
struct Node2 {
	int y, x;
};

queue<Node1> SuyeonQ;
queue<Node2> DevilQ;
Node2 angel;

void init() {
	while (!SuyeonQ.empty()) SuyeonQ.pop();
	while (!DevilQ.empty()) DevilQ.pop();
	for (int y = 0; y < 55; y++) {
		map[y] = "";
	}
}
void input() {
	cin >> H >> W;
	for (int y = 0; y < H; y++) {
		cin >> map[y];
		for (int x = 0; x < map[y].size(); x++) {
			if (map[y][x] == 'D') { angel.y = y; angel.x = x; }
			else if (map[y][x] == 'S') SuyeonQ.push({ y,x,1 });
			else if (map[y][x] == '*') DevilQ.push({ y, x });
		}
	}
}
bool isOut(int ny, int nx) {
	return ny < 0 || nx < 0 || ny >= H || nx >= W;
}

bool isValid() {
	for (int i = 0; i < 4; i++) {
		int ny = angel.y + ditY[i];
		int nx = angel.x + ditX[i];
		if (isOut(ny, nx)) continue;
		if (map[ny][nx] == '.' || map[ny][nx] == 'S') return 1;
	}
	return 0;
}
void solve(int tc) {

	while (!SuyeonQ.empty()) {
		// 여신 상하좌우 못가
		if (isValid() == 0) {
			cout << "#" << tc << " " << "GAME OVER" << "\n";
			return;
		}
		// 악마
		int limitDevil = DevilQ.size();
		for (int k = 0; k < limitDevil; k++) {
			Node2 now2 = DevilQ.front();
			DevilQ.pop();

			for (int i = 0; i < 4; i++) {
				int ny = now2.y + ditY[i];
				int nx = now2.x + ditX[i];
				if (isOut(ny, nx)) continue;
				if (map[ny][nx] == '.' || map[ny][nx] == 'S') {
					map[ny][nx] = '*';
					DevilQ.push({ ny,nx });
				}
			}
		}

		// 수연
		int limitSuyeon = SuyeonQ.size();
		for (int k = 0; k < limitSuyeon; k++) {
			Node1 now = SuyeonQ.front();
			SuyeonQ.pop();

			for (int i = 0; i < 4; i++) {
				int ny = now.y + ditY[i];
				int nx = now.x + ditX[i];
				if (isOut(ny, nx)) continue;
				if (map[ny][nx] == 'D') {
					cout << "#" << tc << " " << now.cnt << "\n";
					return;
				}
				else if (map[ny][nx] == '.') {
					map[ny][nx] = 'S';
					SuyeonQ.push({ ny,nx, now.cnt + 1 });
				}
			}
		}

	}

	cout << "#" << tc << " " << "GAME OVER" << "\n";
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		init();
		input();
		solve(tc);
	}
	return 0;
}