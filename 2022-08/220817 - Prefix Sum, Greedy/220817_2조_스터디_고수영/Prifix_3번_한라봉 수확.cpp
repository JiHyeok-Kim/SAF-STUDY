#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int arr[100001] = { 0 };
int ret[100001] = { 0 };
int N;
int main() 
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	ret[0] = arr[0];
	for (int i = 1; i < N; i++)
	{
		ret[i] = ret[i - 1] + arr[i];
	}

	int maxi = -21e8;
	int sum_num;
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			int a = N - 1;
			for (int b = a - 1; b >= 0; b--)
			{
				if (b == a - 1)
				{
					sum_num = ret[b - 1] * 2;
					if (sum_num > maxi)maxi = sum_num;
				}
				else
				{
					sum_num = ret[a - 1] + ret[b - 1] - arr[b];
					if (sum_num > maxi)maxi = sum_num;
				}
					
			}
			
		}
		if (i == 1)
		{
			int a = 0;
			for (int b = a + 1; b < N; b++)
			{
				if (b == a + 1)
				{
					sum_num = (ret[N-1]-ret[b]) * 2;
					if (sum_num > maxi)maxi = sum_num;
				}
				else
				{
					sum_num = ret[N-1]-arr[a] + ret[N-1] -ret[b] - arr[b];
					if (sum_num > maxi)maxi = sum_num;
				}

			}
			
		}
		if(i == 2)
		{
			int a = 0;
			
			int b = N - 1;
			int c = N / 2;
			if (N % 2 == 0) c -= 1;
			sum_num = (ret[c] - arr[a]) + (ret[b] - ret[c]) - arr[b];
			if (sum_num > maxi)maxi = sum_num;
				
			
		}

	}
	cout << maxi;

	
	
}