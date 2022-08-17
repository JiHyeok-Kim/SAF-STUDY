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
	int N, M, Q;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		arr[x] = y;
	}
	for (int i = 1; i <= M; i++)
	{
		ret[i] = ret[i - 1] + arr[i];
	}


	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int A, B;
		cin >> A >> B;
		cout << ret[B] - ret[A - 1] << '\n';
	}
	
}