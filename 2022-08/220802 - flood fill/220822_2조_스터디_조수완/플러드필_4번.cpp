#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y, x;
	int lev;
};
queue<Node> q;
int map[101][101], used[101][101];
int drY[8] = { -2,-2,-1,-1,1,1,2,2 };
int drX[8] = { -1,1,-2,2,-2,2,-1,1 };
int flag, ans;

int main() {
	int height, width;
	cin >> height >> width;
	int ys, xs, yt, xt;
	cin >> ys >> xs >> yt >> xt;
	q.push({ ys,xs,0 });
	map[yt][xt] = 1;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = now.y + drY[i];
			int nx = now.x + drX[i];
			if (ny < 1 || nx < 1 || nx > width || ny > height) continue;
			if (used[ny][nx] == 1) continue;
			if (map[ny][nx] == 1) {
				ans = now.lev + 1;
				flag = 1;
				break;
			}
			used[ny][nx] = 1;
			q.push({ ny,nx,now.lev + 1 });
		}
		if (flag == 1) break;
	}
	cout << ans;
	return 0;
}