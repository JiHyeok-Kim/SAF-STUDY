#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

struct Point2 {
    int x;
    int y;
    int time;
};
struct Point {
    int x;
    int y;
};

int T, N, M, R, C, L;
int map[51][51] = { 0, };
int used[51][51] = { 0, };
int cnt = 0;
int t = 0;

vector<vector<Point>>v(7);

queue<Point2>q;

void input()
{
    cin >> N >> M >> R >> C >> L;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

}

void Find(Point2 TMP)
{
    while (!q.empty())
    {
        Point2 now = q.front();
        q.pop();
        int Q = map[now.x][now.y] - 1;
        for (int i = 0; i < v[Q].size(); i++)
        {
            int nx = now.x + (v[Q][i]).x;
            int ny = now.y + (v[Q][i]).y;

            if (nx < 0 || ny < 0 || ny >= M || nx >= N)continue;
            if (map[nx][ny] == 0)continue;
            if (used[nx][ny] != 0)continue;

           
            //관이 연결되는지 확인
            int flag = 0;
            //상
            if (v[Q][i].x == -1 && v[Q][i].y == 0)
            {
                if (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 5 || map[nx][ny] == 6) flag = 0;
                else flag = 1;
            }
            //하
            if (v[Q][i].x == 1 && v[Q][i].y == 0)
            {
                if (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 4 || map[nx][ny] == 7) flag = 0;
                else flag = 1;
            }
            if (v[Q][i].x == 0 && v[Q][i].y == 1)
            {
                if (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 6 || map[nx][ny] == 7) flag = 0;
                else flag = 1;
            }
            if (v[Q][i].x == 0 && v[Q][i].y == -1)
            {
                if (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 4 || map[nx][ny] == 5) flag = 0;
                else flag = 1;
            }
            if (flag == 1)continue;

            used[nx][ny] = now.time+1;
            q.push({ nx,ny,now.time+1});
        }
               

    }
    t++;
}

void CNT()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (used[i][j] != 0 && used[i][j] <= L)cnt++;
        }
    }
}

void clear()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            used[i][j] = 0;
        }
    }

    while (!q.empty())
    {
        q.pop();
    }
}

int main()
{
    cin >> T;
    for (int tc = 1; tc < T + 1; tc++)
    {
        input();

        v[0] = { {-1,0},{1,0},{0,1},{0, - 1} };
        v[1] = { {1,0},{-1,0} };
        v[2] = { {0,1},{0,-1} };
        v[3] = { {-1,0},{0,1} };
        v[4] = { {1,0},{0,1} };
        v[5] = { {0,-1},{1,0} };
        v[6] = { {0,-1},{-1,0} };

        Point2 start = { R,C,1};
        used[start.x][start.y] = 1;
        cnt = 0;

        q.push(start);
        Find(start);
        CNT();
        cout << "#"<<tc<<" "<< cnt << '\n';
        clear();

    }
    return 0;
}