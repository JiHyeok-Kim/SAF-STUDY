#include <iostream>
using namespace std;

int village[100001];

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int num, popul;
		cin >> num >> popul;
		village[num] = popul;
	}

	int sum = 0;
	for (int i = 1; i <= m; i++)
	{
		sum += village[i];
		village[i] = sum;
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int s, e;
		cin >> s >> e;
		int output = village[e] - village[s - 1];
		cout << output << "\n";
	}

	return 0;
}