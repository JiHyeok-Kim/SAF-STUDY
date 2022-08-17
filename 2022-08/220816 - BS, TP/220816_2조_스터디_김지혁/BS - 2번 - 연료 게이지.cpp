#include <iostream>
using namespace std;

string str;

int bs(int s, int e)
{
	int gauge = -1;
	while (s <= e)
	{
		int mid = (s + e) / 2;
		if (str[mid] == '#')
		{
			gauge = mid;
			s = mid + 1;
		}
		if (str[mid] == '_')
		{
			e = mid - 1;
		}
	}

	return gauge + 1;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;

		int s = 0;
		int e = str.length() - 1;
		cout << bs(s, e) * 100 / str.length() << "%" << "\n";
	}

	return 0;
}