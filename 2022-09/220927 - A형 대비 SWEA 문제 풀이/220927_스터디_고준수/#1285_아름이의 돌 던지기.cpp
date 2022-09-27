#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;


int min_num = 21e8;
int dis_arr[1001];
int cnt = 0;
void init()
{
	min_num = 21e8;
	cnt = 0;
	for (int i = 0; i < 1001; i++)
	{
		dis_arr[i] = 21e8;
	}
}
int main()
{
	int tc;
	cin >> tc;
	for (int testcase = 0; testcase < tc; testcase++)
	{
		init();
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int dis;
			cin >> dis;
			dis_arr[i] = abs(dis - 0);


		}

		for (int i = 0; i < n; i++)
		{
			if (dis_arr[i] < min_num)
			{
				min_num = dis_arr[i];
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (dis_arr[i] == min_num)
			{
				cnt++;
			}
		}

		cout << '#' << testcase + 1 << ' ' << min_num << ' ' << cnt << '\n';
	}
	return 0;
}