#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N, W, H, ans;
int map[20][20];
int copymap[20][20];
int ditY[4] = { -1,1,0,0 };
int ditX[4] = { 0,0,-1,1 };
vector<int> path;
struct Coord {
	int row, col;
};

void init() {
	ans = 21e8;
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 20; x++) {
			map[y][x] = 0;
		}
	}
}
void input() {
	cin >> N >> W >> H;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			cin >> map[y][x];
		}
	}
}

void makeCopy() {
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 20; x++) {
			copymap[y][x] = map[y][x];
		}
	}
}

void bomb(Coord now) {
	int range = copymap[now.row][now.col];
	copymap[now.row][now.col] = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < range; j++) {
			int ny = now.row + ditY[i] * j;
			int nx = now.col + ditX[i] * j;
			if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
			if (copymap[ny][nx] == 0) continue;
			bomb({ ny,nx });
		}
	}
}

void gravity() {
	stack<int> st;
	int tarCol;
	for (int x = 0; x < W; x++) {
		for (int y = 0; y < H; y++) {
			if (copymap[y][x] != 0) {
				st.push(copymap[y][x]);
				copymap[y][x] = 0;
			}
			tarCol = x;
		}
		int a = st.size();
		for (int k = H - 1; k >= H - a; k--) {
			copymap[k][tarCol] = st.top();
			st.pop();
		}
	}

}

void simul() {

	makeCopy();
	for (int k = 0; k < N; k++)
	{
		int col = path[k];
		for (int row = 0; row < H; row++)
		{
			if (copymap[row][col] > 0) {
				bomb({ row, col });
				break;
			}
		}
		gravity();
	}

}

int remainCnt() {
	int cnt = 0;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			if (copymap[y][x]) cnt++;
		}
	}
	return cnt;
}

void dfs(int lev) {
	if (lev == N) {
		// 맵 전체 남은 벽돌 구하고 최솟값 갱신
		simul();
		ans = min(ans, remainCnt());
		return;
	}

	for (int i = 0; i < W; i++) {
		path.push_back(i);
		dfs(lev + 1);
		path.pop_back();
	}
}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt; 
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		init();
		input();
		dfs(0);
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}