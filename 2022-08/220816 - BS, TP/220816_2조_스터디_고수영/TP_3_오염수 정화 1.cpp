#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cstring>
#include <algorithm>
//#include <cstdlib>
using namespace std;

int arr[100001] = { 0 };
int N;
int mini = 21e7;
int sample1, sample2;
int s = 0, e = 0;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	s = 0;
	e = N - 1;

	while (s < e)
	{
		if (abs(arr[s]) >= abs(arr[e]))
		{
			int sum_num = arr[s] + arr[e];
			if (abs(sum_num) < abs(mini))
			{
				mini = sum_num;
				sample1 = arr[s];
				sample2 = arr[e];
				s++;
			}
			else if (abs(sum_num) == abs(mini))
			{
				if (abs(arr[s]) + abs(arr[e]) > abs(sample1) + abs(sample2))
				{
					sample1 = arr[s];
					sample2 = arr[e];
					s++;
				}
				else s++;
			}
			else s++;
		}
		else
		{
			int sum_num = arr[s] + arr[e];
			if (abs(sum_num) < abs(mini))
			{
				mini = sum_num;
				sample1 = arr[s];
				sample2 = arr[e];
				e--;
			}
			else if (abs(sum_num) == abs(mini))
			{
				if (abs(arr[s]) + abs(arr[e]) > abs(sample1) + abs(sample2))
				{
					sample1 = arr[s];
					sample2 = arr[e];
					e--;
				}
				else e--;
			}
			else e--;
		}
	}

	if (sample1 > sample2)
	{
		int tmp;
		tmp = sample1;
		sample1 = sample2;
		sample2 = tmp;
	}
	cout << sample1 << " " << sample2;
	


   

}