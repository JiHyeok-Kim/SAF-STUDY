#include <iostream>
#include <cmath>
using namespace std;

int N, result, flag;
int num[500];

void init()
{
	num[0] = 2;
	int cnt;
	int idx = 0;
	for (int i = 3; i < 1000; i += 2) {
		cnt = 1;
		for (int j = 3; j <= sqrt(i); j += 2) {
			if (i % j != 0) continue;
			cnt++;
			if (cnt >= 2) break;
		}
		if (cnt == 1) {
			idx++;
			num[idx] = i;
		}
	}

	return;
}

void dfs(int lev, int st, int idx, int sum)
{
	if (lev == 2 && sum > N * 2 / 3 + 1) return;
	if (sum > N) return;
	if (lev == 3) {
		if (sum == N) result++;

		return;
	}

	for (int i = st; i < idx; i++)
	{
		dfs(lev + 1, i, idx, sum + num[i]);
	}

	return;
}

int ans()
{
	int idx = -1;
	for (auto& i : num) {
		idx++;
		if (i == 0) break;
		if (i >= N) break;
	}

	flag = 0;
	result = 0;
	dfs(0, 0, idx, 0);

	return result;
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	init();

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;
		cout << "#" << tc << " " << ans() << "\n";
	}

	return 0;
}