#include <iostream>
using namespace std;

long long M, N, Ti[100000];
long long ans = 999999999;

void bs(long long s, long long e)
{
	while (s <= e)
	{
		long long cnt = 0;
		long long mid = (s + e) / 2;
		for (long long i = 0; i < N; i++)
		{
			cnt += mid / Ti[i];
		}
		if (cnt < M)
		{
			s = mid + 1;
		}
		if (cnt >= M)
		{
			if (ans > mid)
				ans = mid;
			e = mid - 1;
		}
	}

	return;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> Ti[i];
	}

	long long s = 0;
	long long e = 21e8;
	bs(s, e);
	cout << ans;

	return 0;
}