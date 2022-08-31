#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int height[1000001];
int arr[1000001];
bool com(int a, int b)
{
	if (a > b) return true;
	else if (a < b) return false;
	return false;
}
int main()
{
	int tc;
	cin >> tc;
	for (int testcase = 0; testcase < tc; testcase++)
	{
		int cnt = 0;
		int num;
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			cin >> height[i];
		}

		int de = 0;

		for (int i = 0; i < num; i++)
		{
			int number;
			cin >> number;
			arr[number - 1] = height[i];
		}
		de = 0;
		sort(height, height + num, com);
		for (int i = 0; i < num; i++)
		{
			if (arr[i] != height[i])
			{
				cout << "NO" << '\n';
				cnt++;
				break;
			}

		}
		if (cnt == 0)
		{
			cout << "YES" << '\n';
		}

	}





	return 0;
}