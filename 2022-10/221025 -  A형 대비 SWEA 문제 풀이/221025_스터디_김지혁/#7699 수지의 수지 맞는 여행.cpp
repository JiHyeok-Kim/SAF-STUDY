	#include <iostream>
	#include <cstring>
	using namespace std;

	struct Node{
		int y, x, cnt;
	};

	int R, C, maxi;
	string map[20];
	int dat[91];
	int directY[4] = { -1, 1, 0, 0 }; //»óÇÏÁÂ¿ì
	int directX[4] = { 0, 0, -1, 1 };

	void init()
	{
		maxi = 1;
		memset(dat, 0, sizeof(dat));
		cin >> R >> C;
		for (int y = 0; y < R; y++) {
			cin >> map[y];
		}
	}

	void dfs(int ty, int tx, int cnt)
	{
		maxi = max(maxi, cnt);

		for (int i = 0; i < 4; i++)
		{
			int dy = ty + directY[i];
			int dx = tx + directX[i];
			if (dy < 0 || dx < 0 || dy >= R || dx >= C) continue;
			if (dat[map[dy][dx]] == 1) continue;
			dat[map[dy][dx]] = 1;

			dfs(dy, dx, cnt + 1);

			dat[map[dy][dx]] = 0;
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
			dat[map[0][0]] = 1;
			dfs(0, 0, 1);
			cout << "#" << tc << " " << maxi << "\n";
		}

		return 0;
	}