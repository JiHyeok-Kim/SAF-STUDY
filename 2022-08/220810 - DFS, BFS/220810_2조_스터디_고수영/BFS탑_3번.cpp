#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int N, M;
vector<vector<int>>arr(100001);
int used[100001] = { 0 };
int coco;


void input() //1단계
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		arr[from].push_back(to);
		arr[to].push_back(from);
	}
	cin >> coco;
}

int main()
{
	int cnt = 0;
	input();

	queue<int>q;

	used[coco] = 1;
	q.push(coco);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		

		for (int next = 0; next < arr[now].size(); next++)
		{
			if (used[arr[now][next]] == 1)continue;
			used[arr[now][next]] = 1;
			q.push(arr[now][next]);
			cnt++;
		}
	}
	cout << cnt;

}