#include <iostream>
using namespace std;

struct Node {
	int y;
	int x;
};

int N, mini;
Node cordi[12];
bool visit[12];

void init()
{
	mini = 21e8;
	cin >> N;
	for (int i = 0; i < N + 2; i++) {
		cin >> cordi[i].y >> cordi[i].x;
	}

	return;
}

void dfs(int lev, int y, int x, int dist)
{
	if (dist > mini) return;
	if (lev == N)
	{
		int home = dist + abs(cordi[1].y - y) + abs(cordi[1].x - x);
		mini = min(mini, home);
		return;
	}

	for (int i = 2; i < N + 2; i++) {
		if (visit[i] == true) continue;
		visit[i] = true;

		dfs(lev + 1, cordi[i].y, cordi[i].x, dist + abs(cordi[i].y - y) + abs(cordi[i].x - x));

		visit[i] = false;
	}

	return;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		dfs(0, cordi[0].y, cordi[0].x, 0);
		cout << "#" << tc << " " << mini << "\n";
	}

	return 0;
}