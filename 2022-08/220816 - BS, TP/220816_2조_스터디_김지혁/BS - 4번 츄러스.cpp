#include <iostream>
using namespace std;

int churros[10001];
int N, K;
int ans = -1;
void bs(int s, int e)
{
	while (s <= e)
	{
		int cnt = 0;
		int mid = (s + e) / 2;
		for (int i = 1; i <= N; i++)
		{
			cnt += (churros[i] / mid);
		}
		if (cnt >= K)
		{
			if (ans < mid)
				ans = mid;
			s = mid + 1;
		}
		if (cnt < K)
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

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> churros[i];
	}

	int maxChr = -1;
	for (int i = 1; i <= N; i++)
	{
		if (churros[i] > maxChr) maxChr = churros[i];
	}

	int s = 0, e = maxChr;
	bs(s, e);
	cout << ans;

	return 0;
}