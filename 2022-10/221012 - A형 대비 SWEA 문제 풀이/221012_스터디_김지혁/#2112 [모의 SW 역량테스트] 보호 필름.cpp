#include <iostream>
#include <cstring>
using namespace std;

int D, W, K, mini;
int film[14][13][20]; // 0 : A, 1 : B;
bool used[13] = { false, };

void init()
{
	//ÃÊ±âÈ­
	mini = 21e8;
	memset(film, 0, sizeof(film));
	
	cin >> D >> W >> K;
	for (int y = 0; y < D; y++) {
		for (int x = 0; x < W; x++) {
			cin >> film[0][y][x];
		}
	}

	return;
}

int check(int lev, int map[14][13][20])
{
	int flag = 0;
	for (int x = 0; x < W; x++) {
		int n = map[lev][0][x];
		int cnt = 0;
		for (int y = 0; y < D; y++) {
			if (map[lev][y][x] == n) {
				cnt++;
				if (cnt == K) {
					flag++;
					break;
				}
			}
			else {
				n = map[lev][y][x];
				cnt = 1;
			}
		}
		if (flag != x + 1) return 0;
	}
	
	return 1;
}

void dfs(int lev, int idx, int map[14][13][20])
{
	if (lev >= mini) return;
	if (lev == K) {
		mini = K;
		return;
	}
	if (check(lev, map)) {
		mini = min(mini, lev);
		return;
	}

	for (int y = idx; y < D; y++) {
		if (used[y]) continue;
		used[y] = true;
		memcpy(map[lev + 1], map[lev], sizeof(map[lev + 1]));

		for (int i = 0; i < 2; i++) {
			used[y] = true;
			for (int x = 0; x < W; x++) {
				map[lev + 1][y][x] = i;
			}
			dfs(lev + 1, y + 1, map);
			used[y] = false;
			if (lev + 1 >= mini) return;
		}
	}

	return;
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
		dfs(0, 0, film);
		cout << "#" << tc << " " << mini << "\n";
	}

	return 0;
}