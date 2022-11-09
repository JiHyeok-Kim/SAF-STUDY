#include <iostream>
using namespace std;

#define day 86400
#define hour 3600
#define mm 60

string tnow, ttimes, ans;
int now, times, ret;

int trans(string tt)
{
	int t = 0;
	t += (tt[0] - '0') * 10 * hour + (tt[1] - '0') * hour;
	t += (tt[3] - '0') * 10 * mm + (tt[4] - '0') * mm;
	t += (tt[6] - '0') * 10 + (tt[7] - '0');

	return t;
}

void init()
{
	ans = "";
	cin >> tnow >> ttimes;

	now = trans(tnow);
	times = trans(ttimes);

	return;
}

void goANS(int t)
{
	char ch = (t / 10) + '0';
	ans += ch;
	ch = (t % 10) + '0';
	ans += ch;

	return;
}

void transANS(int ret)
{
	int h, d, s;
	h = ret / hour; ret %= hour;
	d = ret / mm; ret %= mm;
	s = ret;

	goANS(h); ans += ':';
	goANS(d); ans += ':';
	goANS(s);

	return;
}

void solve()
{
	ret = (now < times) ? times - now : day - now + times;
	transANS(ret);
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
		solve();
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}