#include <iostream>
#include <unordered_map>
using namespace std;

int map[4][4];
unordered_map<string, bool> um;
int directY[] = { -1, 1, 0, 0 };
int directX[] = { 0, 0, -1, 1 };

void init()
{
	um.clear();
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cin >> map[y][x];
		}
	}

	return;
}

void DFS(int lev, int ty, int tx, string str)
{
	if (lev == 7) {
		um[str] = true;
		return;
	}

	for (int i = 0; i < 4; i++) {

		int dy = ty + directY[i];
		int dx = tx + directX[i];
		if (dy < 0 || dx < 0 || dy >= 4 || dx >= 4) continue;

		char ch = map[dy][dx] + '0';

		DFS(lev + 1, dy, dx, str + ch);
	}
}

int solve()
{
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			DFS(0, y, x, "");
		}
	}

	return um.size();
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		cout << "#" << tc << " " << solve() << "\n";
	}

	return 0;
}