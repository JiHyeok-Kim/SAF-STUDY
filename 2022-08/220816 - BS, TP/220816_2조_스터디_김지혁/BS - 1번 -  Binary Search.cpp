#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];

char bs(int s, int e, int target)
{
	while (s <= e)
	{
		int mid = (s + e) / 2;
		if (arr[mid] == target)
		{
			return 'O';
		}
		if (arr[mid] < target)
		{
			s = mid + 1;
		}
		if (arr[mid] > target)
		{
			e = mid - 1;
		}
	}

	return 'X';
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int k;
	cin >> k;
	int s = 0, e = n - 1;
	for (int i = 0; i < k; i++)
	{
		int target;
		cin >> target;
		cout << bs(s, e, target);
	}

	return 0;
}