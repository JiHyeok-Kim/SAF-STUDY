#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>


/*
1
7
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 1 0 0 0
0 0 1 1 1 0 0
0 0 0 1 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0

*/

using namespace std;
struct Node {
	int x;
	int y;
};

struct D {
	int x;
	int y;
	int d;
	int vect;
};



int map[15][15] = { 0, };
int used[15][15] = { 0, };
int cntPoint[15][15] = { 0 };

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int T, N;
int core;
int lineCnt;
vector<Node>v;
vector<D>lst;
vector<D>one;
vector<D>other;

bool cmp(D t, D v)
{
	return t.d < v.d;
}

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				v.push_back({ i,j });
		}
	}
}


void run(Node now)
{
	for (int i = 0; i < 4; i++)
	{
		int d = 0;
		while (1)
		{
			int nx = now.x + dx[i] * d;
			int ny = now.y + dy[i] * d;
			if (d >= 1)
				if (map[nx][ny] == 1)break;
			if (nx == 0 || ny == 0 || nx == N - 1 || ny == N - 1)
			{

				lst.push_back({ now.x,now.y,d,i });
				break;
			}

			d++;
		}
	}
}


void line(vector<D>V)
{
	for (int i = 0; i < V.size(); i++)
	{
		vector<Node>clean;
		if (used[V[i].x][V[i].y] == 1)continue;
		int flag = 0;
		for (int j = 0; j <= V[i].d; j++)
		{
			int vx = V[i].x + dx[V[i].vect] * j;
			int vy = V[i].y + dy[V[i].vect] * j;
			if (used[vx][vy] == 1)
			{
				flag = 1;
				for (int C = 0; C < clean.size(); C++)
					used[clean[C].x][clean[C].y] = 0;
				break;
			}
			used[vx][vy] = 1;
			clean.push_back({ vx,vy });
		}
		if (flag == 0)
		{
			core++;
			lineCnt += V[i].d;
			clean.clear();
		}
	}
}



int main()
{
	//테스트케이스
	cin >> T;
	for (int tc = 1; tc < T + 1; tc++)
	{
		//입력
		input();
		core = 0;
		lineCnt = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].x == 0 || v[i].y == 0 || v[i].x == N - 1 || v[i].y == N - 1)
			{
				//가장자리에 있는 코어일 경우
				used[v[i].x][v[i].y] = 1;
				core++;
				continue;
			}
			run(v[i]);
			// 최소 노드 길이 lst에 저장
		}

		for (int i = 0; i < lst.size(); i++)
		{
			cntPoint[lst[i].x][lst[i].y]++;
		}

		for (int i = 0; i < lst.size(); i++)
		{
			if (cntPoint[lst[i].x][lst[i].y] == 1)
				one.push_back({ lst[i].x,lst[i].y,lst[i].d,lst[i].vect });

			else other.push_back({ lst[i].x,lst[i].y,lst[i].d,lst[i].vect });
		}

		//1개만 있는좌표
		sort(one.begin(), one.end(), cmp);
		//여러개 있는 좌표
		sort(other.begin(), other.end(), cmp);

		line(one);
		line(other);


		cout << "#" << tc << " " << lineCnt << '\n';
		int ddd = 100;

		//초기화
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				used[i][j] = 0;
		one.clear();
		other.clear();
		v.clear();
		lst.clear();
	}

	return 0;
}