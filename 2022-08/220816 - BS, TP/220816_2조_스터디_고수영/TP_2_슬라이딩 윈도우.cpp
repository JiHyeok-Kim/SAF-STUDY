#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int arr[100000] = { 0 };
int N, W;
int sum=0;
int getSum(int x)
{
	for (int i = 0; i < W; i++)
	{
		sum += arr[i];
	}
	return sum;
}


int main() 
{
	int T;
	cin >> T;
	for (int test_case = 1; test_case < T + 1; test_case++)
	{
		
		
		cin >> N >> W;
		
		int maxi = -21e7;
		int max_id1 = 0, max_id2 = W-1;
		int start = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		sum = 0;
		int ret = getSum(0);

		for (int i = 0; i <= N - W; i++)
		{
			if (ret > maxi)
			{
				maxi = ret;
				max_id1 = start;
				max_id2 = max_id1 + (W - 1);
			}
			ret += arr[i + W];
			//if (arr[i] < 0)ret + arr[i];
			ret -= arr[i];
			start++;
		}
		
		cout << "#" << test_case << " " << max_id1 << " " << max_id2 << " " << maxi << '\n';

		
		
	}
	
}