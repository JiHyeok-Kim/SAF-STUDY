#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cstring>
#include <algorithm>
//#include <cstdlib>
using namespace std;

long long arr[100001];
long long N, M;
long long min_num = 21e7;


void bs(long long s, long long e)
{
	while (s <= e)
	{
		long long mid = (s + e) / 2;
		long long sum_num = 0;
		for (int i = 0; i < N; i++)
		{
			sum_num += mid / arr[i];
		}
		if (sum_num >= M)
		{
			if (min_num > mid)
			{
				min_num = mid;
			}
			e = mid - 1;
		}
		else s = mid + 1;
	}

}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	bs(0, 11e8);

	cout << min_num;

}