#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int arr[10001];
long long sum = 0;
int cnt = 0;
int start = 0;
int main() 
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];

	sum = arr[0];

	int i = 1;
	while(i<=N)
		//(int i = 1; i < N; i++)
	{
		if (sum < M)
		{
			sum += arr[i];
			i++;
		}
		else if (sum == M)
		{
			cnt++;
			sum -= arr[start];
			start++;

		}
		else
		{
			sum -= arr[start];
			start++;
		}
		
	}
	cout << cnt;

}