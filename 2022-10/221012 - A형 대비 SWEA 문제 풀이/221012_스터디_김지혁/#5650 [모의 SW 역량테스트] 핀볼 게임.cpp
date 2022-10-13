#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct Node {
	int y;
	int x;
};

int N, score, maxi;
int map[100][100];
int directY[4] = { -1,1,0,0 }; //상하좌우
int directX[4] = { 0,0,-1,1 };
vector<vector<Node>> portal;

void init()
{
	//초기화
	maxi = 0;
	portal.clear();
	vector<vector<Node>> temp(11);
	portal = temp;
	memset(map, 0, sizeof(map));

	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (6 <= map[y][x] && map[y][x] <= 10) {
				portal[map[y][x]].push_back({y, x});
			}
		}
	}

	return;
}

void block(int idx, int* dt)
{
	if (idx == 1) {
		if (*dt == 0) *dt = 1;
		else if (*dt == 1) *dt = 3;
		else if (*dt == 2) *dt = 0;
		else if (*dt == 3) *dt = 2;
	}
	else if (idx == 2) {
		if (*dt == 0) *dt = 3;
		else if (*dt == 1) *dt = 0;
		else if (*dt == 2) *dt = 1;
		else if (*dt == 3) *dt = 2;
	}
	else if (idx == 3) {
		if (*dt == 0) *dt = 2;
		else if (*dt == 1) *dt = 0;
		else if (*dt == 2) *dt = 3;
		else if (*dt == 3) *dt = 1;
	}
	else if (idx == 4) {
		if (*dt == 0) *dt = 1;
		else if (*dt == 1) *dt = 2;
		else if (*dt == 2) *dt = 3;
		else if (*dt == 3) *dt = 0;
	}
	else if (idx == 5) {
		if (*dt == 0) *dt = 1;
		else if (*dt == 1) *dt = 0;
		else if (*dt == 2) *dt = 3;
		else if (*dt == 3) *dt = 2;
	}

	return;
}

void wormhole(int idx, int wy, int wx, int* py, int* px)
{
	for (int i = 0; i < 2; i++){
		if (portal[idx][i].y != wy || portal[idx][i].x != wx) {
			*py = portal[idx][i].y;
			*px = portal[idx][i].x;
			return;
		}
	}

	return;
}

void run(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		score = 0;
		int dt = i;
		int py = y;
		int px = x;
		while (1)
		{
			py += directY[dt];
			px += directX[dt];
			
			if (py == y && px == x) break;
			else if (py < 0 || px < 0 || py >= N || px >= N) {
				if (dt == 0) dt = 1;
				else if (dt == 1) dt = 0;
				else if (dt == 2) dt = 3;
				else if (dt == 3) dt = 2;
				score++;
				continue;
			}
			else if (map[py][px] == 0) continue;
			else if (1 <= map[py][px] && map[py][px] <= 5) {
				int* direct = &dt;
				block(map[py][px], direct);
				score++;
				continue;
			}
			else if (6 <= map[py][px] && map[py][px] <= 10) {
				int* ppy = &py;
				int* ppx = &px;
				wormhole(map[py][px], py, px, ppy, ppx);
				continue;
			}
			else if (map[py][px] == -1) break;
		}

		if (score > maxi) maxi = score;
	}

	return;
}

int ans()
{
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] != 0) continue;
			run(y, x);
		}
	}

	return maxi;
}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) 
	{
		init();
		cout << "#" << tc << " " << ans() << "\n";
	}

	return 0;
}