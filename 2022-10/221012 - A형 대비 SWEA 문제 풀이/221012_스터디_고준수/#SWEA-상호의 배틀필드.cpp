//문제 설명
//H * W 격자판

#include<iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stdio.h>
using namespace std;


int direct_X[4] = { 0,0,-1,1 };
int direct_Y[4] = { -1,1, 0,0 };

int now_y;
int now_x;
int H, W;
char direct;
char map[20][20];
void play(char c, int y, int x, int d)
{
	if (c == 'U')
	{
		direct = 'U';
		int ny = y - 1;
		int nx = x;
		if (ny < 0 || nx < 0 || ny >= H || nx >= W) return;
		if (map[ny][nx] != '.') return;
		now_y = ny;
		now_x = nx;

	}
	else if (c == 'D')
	{
		direct = 'D';
		int ny = y + 1;
		int nx = x;
		if (ny < 0 || nx < 0 || ny >= H || nx >= W) return;
		if (map[ny][nx] != '.') return;
		now_y = ny;
		now_x = nx;

	}
	else if (c == 'L')
	{
		direct = 'L';
		int ny = y;
		int nx = x - 1;
		if (ny < 0 || nx < 0 || ny >= H || nx >= W) return;
		if (map[ny][nx] != '.') return;
		now_y = ny;
		now_x = nx;

	}
	else if (c == 'R')
	{
		direct = 'R';
		int ny = y;
		int nx = x + 1;
		if (ny < 0 || nx < 0 || ny >= H || nx >= W) return;
		if (map[ny][nx] != '.') return;
		now_y = ny;
		now_x = nx;

	}
	else if (c == 'S')
	{
		if (direct == 'U')
		{
			for (int i = now_y - 1; i >= 0; i--)
			{
				if (map[i][now_x] == '.') continue;
				if (map[i][now_x] == '-') continue;
				if (map[i][now_x] == '#') break;
				if (map[i][now_x] == '*')
				{
					map[i][now_x] = '.';
					break;
				}
			}
		}
		else if (direct == 'D')
		{
			for (int i = now_y + 1; i < H; i++)
			{
				if (map[i][now_x] == '.') continue;
				if (map[i][now_x] == '-') continue;
				if (map[i][now_x] == '#') break;
				if (map[i][now_x] == '*')
				{
					map[i][now_x] = '.';
					break;
				}
			}
		}
		else if (direct == 'L')
		{
			for (int i = now_x - 1; i >= 0; i--)
			{
				if (map[now_y][i] == '.') continue;
				if (map[now_y][i] == '-') continue;
				if (map[now_y][i] == '#') break;
				if (map[now_y][i] == '*')
				{
					map[now_y][i] = '.';
					break;
				}
			}
		}
		else if (direct == 'R')
		{
			for (int i = now_x + 1; i < W; i++)
			{
				if (map[now_y][i] == '.') continue;
				if (map[now_y][i] == '-') continue;
				if (map[now_y][i] == '#') break;
				if (map[now_y][i] == '*')
				{
					map[now_y][i] = '.';
					break;
				}
			}
		}
	}
}



int main()
{
	int tc;
	cin >> tc;

	for (int testcase = 0; testcase < tc; testcase++)
	{


		cin >> H >> W;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				char st;
				cin >> st;
				map[i][j] = st;
				if (map[i][j] == '^')
				{
					direct = 'U';
					now_y = i;
					now_x = j;
				}
				else if (map[i][j] == 'v')
				{
					direct = 'D';
					now_y = i;
					now_x = j;
				}
				else if (map[i][j] == '<')
				{
					direct = 'L';
					now_y = i;
					now_x = j;
				}
				else if (map[i][j] == '>')
				{
					direct = 'R';
					now_y = i;
					now_x = j;
				}
			}
		}


		int word_size;
		cin >> word_size;
		string word;
		cin >> word;
		map[now_y][now_x] = '.';
		for (int i = 0; i < word_size; i++)
		{
			play(word[i], now_y, now_x, direct);
		}
		if (direct == 'U')
		{
			map[now_y][now_x] = '^';
		}
		else if (direct == 'D')
		{
			map[now_y][now_x] = 'v';
		}
		else if (direct == 'L')
		{
			map[now_y][now_x] = '<';
		}
		else if (direct == 'R')
		{
			map[now_y][now_x] = '>';
		}


		cout << '#' << testcase + 1 << ' ';
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cout << map[i][j];
			}
			cout << '\n';
		}
	}

}

//* * * . . . .
//* - . . # * *
//# < . * * * *
//
//* * . . . . v
//. - . . # . .
//# . . . . . .
//
//SURSSSSUSLSRSSSURRDSRDS