#include <iostream>
using namespace std;

int H, W, N, ty, tx;
string map[20];
char tank;
int directY[4] = { -1,1,0,0 };
int directX[4] = { 0,0,-1,1 };

void init()
{
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		cin >> map[i];
	}

	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			if (map[y][x] == '^' || map[y][x] == 'v' || map[y][x] == '<' || map[y][x] == '>') {
				ty = y, tx = x;
				tank = map[ty][tx];
				return;
			}
		}
	}

	return;
}

void goMove(int dt)
{
	if (dt == 0) map[ty][tx] = '^';
	else if (dt == 1) map[ty][tx] = 'v';
	else if (dt == 2) map[ty][tx] = '<';
	else if (dt == 3) map[ty][tx] = '>';
	tank = map[ty][tx];
	int dy = ty + directY[dt];
	int dx = tx + directX[dt];
	if (dy < 0 || dx < 0 || dy >= H || dx >= W) return;
	if (map[dy][dx] == '*' || map[dy][dx] == '#' || map[dy][dx] == '-') return;
	map[ty][tx] = '.';
	map[dy][dx] = tank;
	ty = dy, tx = dx;

	return;
}

void goShoot()
{
	int dt;
	if (tank == '^') dt = 0;
	else if (tank == 'v') dt = 1;
	else if (tank == '<') dt = 2;
	else if (tank == '>') dt = 3;
	for (int i = 1; i < 20; i++) {
		int dy = ty + directY[dt] * i;
		int dx = tx + directX[dt] * i;
		if (dy < 0 || dx < 0 || dy >= H || dx >= W) break;
		if (map[dy][dx] == '#') break;
		if (map[dy][dx] == '*') {
			map[dy][dx] = '.';
			break;
		}
	}

	return;
}

void goTank(char cmd) 
{
	if (cmd == 'S') goShoot();
	else if (cmd == 'U') goMove(0);
	else if (cmd == 'D') goMove(1);
	else if (cmd == 'L') goMove(2);
	else if (cmd == 'R') goMove(3);

	return;
}

void command()
{
	cin >> N;
	string str;
	cin >> str;
	for (int i = 0; i < N; i++) {
		char cmd = str[i];
		goTank(cmd);
	}

	return;
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		command();

		cout << "#" << tc << " ";
		for (int i = 0; i < H; i++) {
			cout << map[i] << "\n";
		}
	}

	return 0;
}