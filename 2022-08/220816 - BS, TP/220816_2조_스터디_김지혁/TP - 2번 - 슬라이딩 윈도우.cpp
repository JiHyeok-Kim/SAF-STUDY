#include <iostream>
using namespace std;

int art[100000];
int n, w;

int getSum()
{
	int sum = 0;
	for (int i = 0; i < w; i++) sum += art[i];
	return sum;
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
		cin >> n >> w;
		for (int i = 0; i < n; i++)
		{
			cin >> art[i];
		}

		int sum = getSum();
		int maxi = sum;
		int maxiS = 0, maxiE = w - 1;
		for (int i = 0; i < n - w; i++)
		{
			sum += art[i + w];
			sum -= art[i];
			if (sum > maxi)
			{
				maxi = sum;
				maxiS = i + 1;
				maxiE = i + w;
			}
		}
		cout << "#" << tc << " " << maxiS << " " << maxiE << " " << maxi << "\n";
	}

	return 0;
}