#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node {
	int y, x;
	int lev;
};
string map[100];
int map1[100][100], used[100][100];
int lastLev, cnt = 0;
int directY[4] = { 0,0,1,-1 };
int directX[4] = { 1,-1,0,0 };
queue<Node> q;

int main() {
	int width, height;
	cin >> width >> height;
	for (int y = 0; y < height; y++) {
		cin >> map[y];
	}
	int yt, xt;
	cin >> xt >> yt;
	q.push({ yt - 1,xt - 1,3 });
	used[yt - 1][xt - 1] = 1;
	lastLev = 3;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + directY[i];
			int nx = now.x + directX[i];
			if (ny < 0 || nx < 0 || ny >= height || nx >= width) continue;
			if (used[ny][nx] == 1 || map[ny][nx] == '0') continue;
			used[ny][nx] = 1;
			q.push({ ny,nx,now.lev + 1 });
			lastLev = now.lev + 1;
		}
	}
	cout << lastLev << '\n';
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (map[y][x] == '1' && used[y][x] == 0) cnt++;
		}
	}
	cout << cnt << '\n';

	return 0;
}