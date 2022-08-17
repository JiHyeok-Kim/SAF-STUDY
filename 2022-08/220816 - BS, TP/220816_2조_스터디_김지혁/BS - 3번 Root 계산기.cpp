#include <iostream>
using namespace std;

long long n;
long long ans = -1;

void bs(long long s, long long e)
{
	while (s <= e)
	{
		long long mid = (s + e) / 2;
		if (mid * mid <= n)
		{
			if (ans < mid) ans = mid;
			s = mid + 1;
		}
		if (mid * mid > n)
		{
			e = mid - 1;
		}
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	long long s = 0;
	long long e = n;

	bs(s, e);
	cout << ans;

	return 0;
}