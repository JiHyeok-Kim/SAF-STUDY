#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int N, M, K;
vector<vector<int>>arr(100001);
int used[100001] = { 0 };
int hp[100001] = { 0 };
int cnt = 0;


void input() //1단계
{
	cin >> N >>M >> K;
	for (int i = 0; i < M; i++)
	{
		int from, to ,cost;
		cin >> from >> to>>cost;
		arr[from].push_back(to);
		arr[to].push_back(from);
		hp[to] = cost;
	}

}

int main()
{
	input();
	queue<int>q;

	used[1] = 1;
	q.push(1);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int next = 0; next < arr[now].size(); next++)
		{
			if (used[arr[now][next]] != 0)continue;
			if (used[now] + hp[arr[now][next]] > K)continue; // 체력을 넘어가면 무시
			used[arr[now][next]] = used[now] + hp[arr[now][next]];

			cnt++;
			q.push(arr[now][next]);
		}
	}

	cout << cnt;
}