#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>

using namespace std;

int map[20][20] = { 0, };
int copymap[20][20] = { 0, };
int used[20][20] = { 0, };

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int T;
int N, W, H;

int blockCnt = 0;

struct Node {
	int x;
	int y;
};

int cnt = 0;
int mini = 21e6;


vector<int>v;

void input()
{
	cin >> N >> W >> H;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> map[i][j];
		}
	}
}

void makecopy()
{
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			copymap[i][j] = map[i][j];
}

void boom() 
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (used[i][j] == 1)
				copymap[i][j] = 0;
		}
	}
}

void marking(Node now)
{
	for (int i = 1; i < copymap[now.x][now.y]; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int nx = now.x + dx[j]*i;
			int ny = now.y + dy[j]*i;

			if (nx < 0 || ny < 0 || nx >= H || ny >= W)continue;
			if (used[nx][ny] == 1)continue;
			if (copymap[nx][ny] == 0)continue;
			used[nx][ny] = 1;
			blockCnt++;
			marking({ nx,ny });
		}
	}
}

void gravity()
{
	for (int j = 0; j < W; j++)
	{
		int zerocnt = 0;
		for (int i = H - 1; i >= 0; i--)
		{
			if (copymap[i][j] == 0)zerocnt++;
			else
			{
				if (zerocnt != 0)
				{
					copymap[i + zerocnt][j] = copymap[i][j];
					copymap[i][j] = 0;
				}
			}
		}

	}
}
void usedClean()
{
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			used[i][j] = 0;
}

void check(vector<int>path)
{
	for (int p = 0; p < path.size(); p++)
	{
		for (int i = 0; i < H; i++)
		{
			int j = path[p];
			if (copymap[i][j] != 0)
			{
				//used에 터뜨릴거 체크
				blockCnt++;
				used[i][j] = 1;
				marking({ i,j });

				//터뜨리기
				boom();

				//중력 블록
				gravity();

				//used정리
				usedClean();
				break;

			}
		}
	}
}


void countBlock()
{
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			if (copymap[i][j] != 0)cnt++;
	if (cnt < mini)mini = cnt;
}

void dfs(int lev, vector<int> path)
{
	if (lev == N)
	{
		// 새로운 복사본 생성
		if (path[0] == 2 && path[1] == 2 && path[2] == 6)
			int pppp = 10;

		makecopy();
		blockCnt = 0;
		check(path);

		//남은 블록 개수 세기
		cnt = 0;
		countBlock();

		
		return;
	}

	for (int i = 0; i < W; i++)
	{
		path.push_back(i);
		dfs(lev + 1, path);
		path.pop_back();
	}
}

int main()
{
	cin >> T;
	for (int tc = 1; tc < T + 1; tc++)
	{
		//입력
		input();
		mini = 21e6;
		//조합
		dfs(0,v);
		cout <<"#"<<tc<<" "<<mini<<'\n';

	}
}