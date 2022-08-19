#include <iostream>
using namespace std;

int arr[2001];

int N, L;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		int point;
		cin >> point;
		arr[point]++;
	}

	int ans = 0;
	int i = 1;
	while (1)
	{
		if (arr[i] == 1)
		{
			ans++;
			i += L;
		}
		else i++;

		if (i > 1000) break;
	}
	cout << ans;

	return 0;
}