#include <iostream>
using namespace std;

int map[10][10];
int datLeft[20];
int datRight[20];
int row[10];

int dy[4] = { 1,1,-1,-1 };
int dx[4] = { -1,1,-1,1 };

int n;

int answer = 0;

void dfs(int lev) {
	if (lev == n) {
		answer++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (row[i] == 1) continue;
		if (datLeft[lev + i] != 0) continue;
		if (datRight[lev - i + 10] != 0) continue;
		datRight[lev - i + 10] = 1;
		datLeft[lev + i] = 1;
		row[i] = 1;
		map[lev][i] = 1;
		dfs(lev + 1);
		datLeft[lev + i] = 0;
		datRight[lev - i + 10] = 0;
		map[lev][i] = 0;
		row[i] = 0;
	}
}

int main()
{
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		cin >> n;

		answer = 0;

		dfs(0);

		cout << "#" << t << " " << answer << '\n';
	}
	return 0;
}