//문제 설명

#include<iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stdio.h>
using namespace std;
int now_y; //현재 y의 위치
int now_x; //현재 x의 위치
int H, W; // 격자판 세로 가로
char direct; //방향을 나타내는 문자
char map[20][20]; //격자판
void play(char c, int y, int x,int d) //c 명령문자 , y = now_y , x= now_x d=방향
{
	//명령어가 U 일때
	if (c == 'U')
	{
		direct = 'U';
		int ny = y - 1;
		int nx = x;
		if (ny<0 || nx <0 || ny >=H || nx >= W) return;
		if (map[ny][nx] != '.') return;
		now_y = ny;
		now_x = nx;
		
	}
	//명령어가 D일떄
	else if (c == 'D')
	{
		direct = 'D';
		int ny = y + 1;
		int nx = x;
		if (ny<0 || nx <0 || ny >=H || nx >= W) return;
		if (map[ny][nx] != '.') return;
		now_y = ny;
		now_x = nx;
		
	}
	//명령어가 L 일떄
	else if (c == 'L')
	{
		direct = 'L';
		int ny = y;
		int nx = x-1;
		if (ny<0 || nx <0 || ny >=H || nx >= W) return;
		if (map[ny][nx] != '.') return;
		now_y = ny;
		now_x = nx;
		
	}
	//명령어가 R일떄
	else if (c == 'R')
	{
		direct = 'R';
		int ny = y;
		int nx = x+1;
		if (ny<0 || nx <0 || ny >=H || nx >= W) return;
		if (map[ny][nx] != '.') return;
		now_y = ny;
		now_x = nx;
		
	}
	//명령어가 S일떄
	else if (c == 'S')
	{
		//명령어가 S인데 방향이 U이면 현재 좌표에서 위까지 쭉 탐색
		if (direct == 'U')
		{
			for (int i = now_y-1; i >=0; i--)
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
	//테스트 케이스 
	for (int testcase = 0; testcase < tc; testcase++)
	{
		
		
		cin >> H >> W;
		//좌표 입력 받으면서 방향을 나타내는 문자면 now_y now_x 에 좌표 값 넣기
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				char st;
				cin >> st;
				map[i][j]=st;
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
		map[now_y][now_x] = '.'; // 처음에 내가 있는 좌표 '<' 같은거 평지로 바꿔주기
		for (int i = 0; i < word_size; i++)
		{
			//명령어 수 만큼 play 함수로 판단하기
			play(word[i],now_y,now_x,direct);
		}
		if (direct == 'U')
		{
			map[now_y][now_x] = '^'; // 다 끝난 후 now_y now_x 의 좌표의 평지를 방향 문자로 바꾸기
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
		
		
		cout << '#' << testcase+1<< ' ';
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
