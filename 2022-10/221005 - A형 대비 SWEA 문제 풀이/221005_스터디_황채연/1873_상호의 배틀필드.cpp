#include <iostream>
#include <string>
using namespace std;

int T, H, W, N;
char MAP[20][21];
string in;

typedef struct {
	int y, x;
	int d;
}POSI;
POSI target;

// 상하좌우
const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

void Solve(int tc) {
	int ny, nx;
	for (int i = 0; i < in.size(); ++i) {
		if (in[i] == 'S') {
			for (int step = 1; step < W; ++step) {
				ny = target.y + step * dy[target.d];
				nx = target.x + step * dx[target.d];
				if (ny < 0 || ny >= H || nx < 0 || nx >= W) break;
				if (MAP[ny][nx] == '*') {
					MAP[ny][nx] = '.';
					break;
				}
				if (MAP[ny][nx] == '#') break;
			}
		}
		else {
			if (in[i] == 'U') {
				target.d = 0;
				ny = target.y + dy[target.d];
				nx = target.x + dx[target.d];
				MAP[target.y][target.x] = '^';
			}
			if (in[i] == 'D') {
				target.d = 1;
				ny = target.y + dy[target.d];
				nx = target.x + dx[target.d];
				MAP[target.y][target.x] = 'v';
			}
			if (in[i] == 'L') {
				target.d = 2;
				ny = target.y + dy[target.d];
				nx = target.x + dx[target.d];
				MAP[target.y][target.x] = '<';
			}
			if (in[i] == 'R') {
				target.d = 3;
				ny = target.y + dy[target.d];
				nx = target.x + dx[target.d];
				MAP[target.y][target.x] = '>';
			}
			
			if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
			if (MAP[ny][nx] == '.') {
				char temp = MAP[target.y][target.x];
				MAP[target.y][target.x] = '.';
				MAP[ny][nx] = temp;
				target.y = ny, target.x = nx;
			}
		}
	}

	cout << "#" << tc << " ";
	for (int y = 0; y < H; ++y) {
		cout << MAP[y] << "\n";
	}
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> H >> W;
		for (int y = 0; y < H; ++y) {
			cin >> MAP[y];
			for (int x = 0; x < W; ++x) {
				if (MAP[y][x] == '^' || MAP[y][x] == 'v' || MAP[y][x] == '<' || MAP[y][x] == '>') {
					target.y = y, target.x = x;
					if (MAP[y][x] == '^') target.d = 0;
					if (MAP[y][x] == 'v') target.d = 1;
					if (MAP[y][x] == '<') target.d = 2;
					if (MAP[y][x] == '>') target.d = 3;
				}
			}
		}
		cin >> N;
		cin >> in;
		Solve(tc);
	}
	return 0;
}