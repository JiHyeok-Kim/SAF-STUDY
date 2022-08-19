#include <iostream>

using namespace std;

int line[100001];
int acc[100001];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> line[i];
	}

	acc[0] = line[0];
	for (int i = 1; i < n; i++)
	{
		acc[i] = acc[i - 1] + line[i];
	}

	for (int x = 0; x < m; x++)
	{
		int i, j;
		cin >> i >> j;
		if (i == 1) { cout << acc[j - 1] << "\n"; continue; }
		cout << acc[j - 1] - acc[i - 2] << "\n";
	}

	return 0;
}