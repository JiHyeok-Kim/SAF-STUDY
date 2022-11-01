#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int map[51][51];

void init()
{
	memset(map, 0, sizeof(map));
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int y, x;
		cin >> y >> x;
		map[y][x] = 1;
		map[x][y] = 1;
	}

	return;
}

int ans()
{
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			for (int k = j + 1; k <= N; k++) {
				if (map[i][j] == 0) continue;
				if (map[j][k] == 0) continue;
				if (map[k][i] == 0) continue;
				cnt++;
			}
		}
	}

	return cnt;
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