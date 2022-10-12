#include <iostream>
using namespace std;

int N, maxi, mini, ans;
int num[12];
int giho[4];

void init()
{
	ans = 0;
	cin >> N;
	for (int i = 0; i < 4; i++) {
		cin >> giho[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	return;
}

void dfs(int lev, int sum)
{
	if (lev == N)
	{
		if (sum < mini) mini = sum;
		if (sum > maxi) maxi = sum;

		return;
	}

	for (int i = 0; i < 4; i++) {
		if (giho[i] == 0) continue;

		giho[i]--;
		if (i == 0) dfs(lev + 1, sum + num[lev]);
		else if (i == 1) dfs(lev + 1, sum - num[lev]);
		else if (i == 2) dfs(lev + 1, sum * num[lev]);
		else if (i == 3) dfs(lev + 1, sum / num[lev]);
		giho[i]++;

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

		mini = 21e8;
		maxi = -21e8;
		dfs(1, num[0]);

		ans = maxi - mini;
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}