#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
int T;
int N;

struct point {
   int x;
   int y;
};

int map[100][100] = { 0, };

// 상 하 좌 우
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int px, py;

vector<point> potal[11];
vector<point>v;

int cnt;
int maxi;

point start;

void input()
{
   cin >> N;
   for (int i = 0; i < N; i++)
   {
      for (int j = 0; j < N; j++)
      {
         cin >> map[i][j];

         if (map[i][j] == 0) v.push_back({ i,j });

         if (map[i][j] >= 6 && map[i][j] <= 10)
         {
            //포탈 좌표 입력
            potal[map[i][j]].push_back({ i,j });
         }
      }
   }
}

void run(point now, int vect)
{
   while (1)
   {
      int nx = now.x + dx[vect];
      int ny = now.y + dy[vect];

      //벽일경우
      if (nx < 0 || ny < 0 || nx >= N || ny >= N)
      {
         //방향전환
         if (vect == 0)vect = 1;
         else if (vect == 1)vect = 0;
         else if (vect == 2)vect = 3;
         else if (vect == 3)vect = 2;
         //nx = now.x;
         //ny = now.y;

         cnt++;
      }
      //블록일경우
      else if (map[nx][ny] >= 1 && map[nx][ny] <= 5)
      {
         //상
         if (vect == 0)
         {
            //1,4,5 블럭일때
            if (map[nx][ny] == 1 || map[nx][ny] == 4 || map[nx][ny] == 5)
            {
               //방향전환
               vect = 1;
               cnt++;
            }
            //2,3 일때
            else
            {
               //2일때
               if (map[nx][ny] == 2)
               {
                  vect = 3;
                  cnt++;

               }
               //3일때
               else if (map[nx][ny] == 3)
               {
                  vect = 2;
                  cnt++;

               }
            }
         }
         //하
         else if (vect == 1)
         {
            //2,3,5 블럭일때
            if (map[nx][ny] == 2 || map[nx][ny] == 3 || map[nx][ny] == 5)
            {
               //방향전환
               vect = 0;
               cnt++;
            }
            //1,4 일때
            else
            {
               //1일때
               if (map[nx][ny] == 1)
               {
                  vect = 3;
                  cnt++;

               }
               //4일때
               else if (map[nx][ny] == 4)
               {
                  vect = 2;
                  cnt++;
               }
            }
         }
         //좌
         else if (vect == 2)
         {
            //3,4,5 블럭일때
            if (map[nx][ny] == 3 || map[nx][ny] == 4 || map[nx][ny] == 5)
            {
               //방향전환
               vect = 3;
               cnt++;
            }
            //1,2 일때
            else
            {
               //1일때
               if (map[nx][ny] == 1)
               {
                  vect = 0;
                  cnt++;
               }
               //2일때
               else if (map[nx][ny] == 2)
               {
                  vect = 1;
                  cnt++;
               }
            }
         }
         //우
         else if (vect == 3)
         {
            //1,2,5 블럭일때
            if (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 5)
            {
               //방향전환
               vect = 2;
               cnt++;
            }
            //3,4 일때
            else
            {
               //3일때
               if (map[nx][ny] == 3)
               {
                  vect = 1;
                  cnt++;
               }
               //4일때
               else if (map[nx][ny] == 4)
               {
                  vect = 0;
                  cnt++;
               }
            }
         }
      }
      //포탈일때
      else if (map[nx][ny] >= 6 && map[nx][ny] <= 10)
      {
         if (potal[map[nx][ny]][0].x == nx && potal[map[nx][ny]][0].y == ny)
         {
            px = potal[map[nx][ny]][1].x;
            py = potal[map[nx][ny]][1].y;
            nx = px;
            ny = py;
         }
         else
         {
            px = potal[map[nx][ny]][0].x;
            py = potal[map[nx][ny]][0].y;
            nx = px;
            ny = py;
         }
      }

      now = { nx,ny };
      if (((map[now.x][now.y] == 999) || (map[now.x][now.y] == -1)))break;
   }
}

int main()
{
   cin >> T;
   for (int tc = 1; tc < T + 1; tc++)
   {
      //입력
      input();
      maxi = -21e7;
      //탐색
      for (int i = 0; i < v.size(); i++)
      {

         //시작 좌표
         start = { v[i].x ,v[i].y };

         //4방향
         for (int k = 0; k < 4; k++)
         {
            cnt = 0;
            map[start.x][start.y] = 999;
            run(start, k);
            map[start.x][start.y] = 0;

            //최대값 비교
            maxi = max(maxi, cnt);

         }
      }

      //potal.clear();
        for(int i = 0; i<11; i++)
        {
            potal[i].clear();
        }
        v.clear();


      cout << "#" << tc << " " << maxi << "\n";

   }
   return 0;
}