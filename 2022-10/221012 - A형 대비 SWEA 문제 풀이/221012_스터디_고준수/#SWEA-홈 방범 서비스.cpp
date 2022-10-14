#include<iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stdio.h>
using namespace std;
int map[20][20];
int cnt_house = 0;
int result_cnt_house = -1;
int N; //맵 크기
int M; //한 가구당 지불 할 수 있는 돈
int direct_Y[4] = { -1,1,0,0 };
int direct_X[4] = { 0,0,-1,1 };
int ex = 0;
int cnt = 1; //초기화 해야댐
int used[20][20];
typedef struct {
	int y_idx;
	int x_idx;
	int lev;
}Node;


queue<Node> q;
void init(int n)
{
	while (!q.empty())
	{
		q.pop();
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			used[i][j] = 0;
		}
	}
	cnt_house = 0;
}



void bfs(int y, int x, int K, int cost, int n)
{
	init(n);

	if (map[y][x] == 1)
	{
		cnt_house += 1;
	}
	q.push({ y,x,1 });
	used[y][x] = 1;
	while (!q.empty())
	{
		Node now = q.front();
		q.pop();
		if (now.lev == K) continue;

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y_idx + direct_Y[i];
			int nx = now.x_idx + direct_X[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (used[ny][nx] == 1) continue;
			if (map[ny][nx] == 1)
			{
				cnt_house += 1;
				used[ny][nx] = 1;
				q.push({ ny,nx,now.lev + 1 });
			}
			else if (map[ny][nx] == 0)
			{
				used[ny][nx] = 1;
				q.push({ ny,nx,now.lev + 1 });
			}


		}

	}
	ex = K * K + (K - 1) * (K - 1);
	if (ex > cnt_house * cost) return;
	if (result_cnt_house < cnt_house)
	{
		result_cnt_house = cnt_house;
	}
	//result_cnt_house = max(result_cnt_house, cnt_house);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int testcase = 0; testcase < tc; testcase++)
	{

		result_cnt_house = 0;
		cin >> N;
		cin >> M;
		//N * N의 map 에 값 넣기
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
			}
		}

		for (int k = 1; k <= N + 1; k++)
		{
			if (k >= 3)
			{
				for (int i = k / 2; i <= N - (k / 2); i++)
				{
					for (int j = k / 2; j <= N - (k / 2); j++)
					{
						bfs(i, j, k, M, N);
					}
				}
			}
			else
			{
				for (int i = 0; i < N; i++)
				{
					for (int j = 0; j < N; j++)
					{
						bfs(i, j, k, M, N);
					}
				}
			}

		}

		cout << '#' << testcase + 1 << ' ' << result_cnt_house << '\n';
	}





	return 0;
}