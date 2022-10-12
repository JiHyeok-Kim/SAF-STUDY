#include <iostream>
using namespace std;

int D, sM, tM, Y;
int pay[12];
int ans;

void goDfs(int lev, int cost)
{
	if (lev > 11) {
		if (cost < ans) ans = cost;
		return;
	}
	for (int i = 0; i < 2; i++) {
		if (i == 0) goDfs(lev + 1, cost + pay[lev]);
		else goDfs(lev + 3, cost + tM);
	}

	return;
}

void getMoney()
{
	for (int i = 0; i < 12; i++) {
		int n;
		cin >> n;
		pay[i] = n * D;
		if (sM < pay[i]) pay[i] = sM;
	}

	goDfs(0, 0);
	if (Y < ans) ans = Y;

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> D >> sM >> tM >> Y;
		ans = 21e8;
		getMoney();
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}