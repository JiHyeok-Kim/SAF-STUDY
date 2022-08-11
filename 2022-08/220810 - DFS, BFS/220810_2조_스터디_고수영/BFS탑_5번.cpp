#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int N, T;
vector<vector<int>>arr(101);
int used[101] = { 0 };
int coco;
int koko;


void input() //1단계
{
	cin >> N >>T;
	for (int i = 0; i < T; i++)
	{
		int from, to;
		cin >> from >> to;
		arr[from].push_back(to);
		arr[to].push_back(from);
	}
	cin >> coco>>koko;
}

int main()
{
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
		}

	}

	if (used[coco] == used[koko])cout << "YES";
	else cout << "NO";
}