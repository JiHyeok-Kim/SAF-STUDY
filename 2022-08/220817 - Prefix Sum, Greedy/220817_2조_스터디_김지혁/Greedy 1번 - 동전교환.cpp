#include <iostream>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int coin[4] = { 500, 100, 50, 10 };
	int change;
	cin >> change;

	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		cnt += change / coin[i];
		change = change % coin[i];
	}

	cout << cnt;

	return 0;
}