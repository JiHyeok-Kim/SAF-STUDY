#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int arr[100001] = { 0 };
int ret[100001] = { 0 };
int main() 
{
	
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	ret[0] = arr[0];
	for (int i = 1; i < N; i++)
	{
		ret[i] = ret[i - 1] + arr[i];
	}
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		int sumA = ret[b - 1];
		int sumB = ret[a - 1];
		cout <<sumA-sumB+arr[a-1]  << '\n';
	}
}