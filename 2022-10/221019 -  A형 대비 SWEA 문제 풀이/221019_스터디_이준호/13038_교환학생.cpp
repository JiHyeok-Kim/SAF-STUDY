#include <iostream>
using namespace std;

int n, ans, idx, sum, cnt;
int week[7];

void input()
{
	ans = 21e8;
	cin >> n;
	for (int i = 0; i < 7; i++) {
		cin >> week[i];
	}
}

void solve() {
	for (int i = 0; i < 7; i++) {
		if (week[i]) {
			idx = i;
			sum = 0;
			cnt = 0;
			while (1)
			{
				if (sum == n) break;
				sum += week[idx];
				idx = (idx + 1) % 7;
				cnt++;
			}
			ans = min(ans, cnt);
		}
	}
}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++)
	{
		input();
		solve();
		cout << "#" << tc << " " << ans << "\n";
	}


	return 0;
}