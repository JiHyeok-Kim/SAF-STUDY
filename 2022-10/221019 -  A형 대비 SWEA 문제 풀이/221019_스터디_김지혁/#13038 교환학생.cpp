#include <iostream>
using namespace std;

int day, week[7], clssW;

void init()
{
	cin >> day;
	clssW = 0;
	for (int i = 0; i < 7; i++) {
		cin >> week[i];
		if (week[i] == 1) clssW++;
	}

	return;
}

int stClass(int st)
{
	int cnt = 0;
	int cntD = 0;
	for (int i = st; i < 7; i++)
	{
		cnt++;
		if (week[i] == 1) cntD++;
		if (cntD == day) return cnt;
	}
	int rest = day - cntD;

	if (rest > clssW) {
		while (1)
		{
			rest -= clssW;
			cntD += clssW;
			cnt += 7;
			if (rest <= clssW) break;
		}
	}

	for (int i = 0; i < 7; i++)
	{
		cnt++;
		if (week[i] == 1) cntD++;
		if (cntD == day) return cnt;
	}
}

int ans()
{
	int mini = 21e8;

	for (int i = 0; i < 7; i++)
	{
		if (week[i] == 1) {
			mini = min(mini, stClass(i));
		}
	}

	return mini;
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
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