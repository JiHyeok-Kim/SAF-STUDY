#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

struct point {
    int x;
    int y;
};

vector<point>V;

int T, N;
int map[15][15] = { 0, };
int core = 0;
int line = 0;
int maxi = -21e8;
int mini = 21e8;

//상 하 좌 우 X
int dx[5] = { -1,1,0,0,0 };
int dy[5] = { 0,0,-1,1,0 };

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            //노드일 경우
            if (map[i][j] == 1)
            {
                //가장자리일 경우
                if (i == 0 || i == N - 1 || j == 0 || j == N - 1)
                {
                    core++;
                    continue;
                }
                //일반 경우
                V.push_back({ i,j });
            }
        }
    }

}

int Find()
{
    int cnt_line = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 2)cnt_line++;
        }
    }
    return cnt_line;
}

int isValue(point now_test, int vect)
{
    while (1)
    {
        int nx = now_test.x + dx[vect];
        int ny = now_test.y + dy[vect];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N)return 1;
        if (map[nx][ny] == 1 || map[nx][ny] == 2)return 0;

        now_test = { nx,ny };
    }
}

void drawLine(point now_draw, int vect, int num)
{
    while (1)
    {
        int nx = now_draw.x + dx[vect];
        int ny = now_draw.y + dy[vect];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N) return;

        map[nx][ny] = num;
        now_draw = { nx,ny };
    }

}

void dfs(int cnt_dfs)
{
    if (cnt_dfs == V.size())
    {
        //2의(전선) 개수 세기
        int tmp = Find();
        line = tmp;
        //코어 수가 최대값 보다 같거나 클 경우
        if (core >= maxi)
        {
            //같을 경우
            if (core == maxi)
            {
                //전선이 더 짧을 경우
                if (line < mini)
                {
                    mini = line;
                    return;
                }
                return;
            }
            //코어 개수가 클 경우
            maxi = core;
            mini = line;
            return;
        }
        return;
    }

    //5가지 방향배열
    for (int i = 0; i < 5; i++)
    {
        //전선을 안그을 경우
        if (i == 4)
        {
            cnt_dfs++;
            dfs(cnt_dfs);
            cnt_dfs--;
            continue;
        }
        //전선을 긋는 경우
        else
        {
            point now = V[cnt_dfs];
            int flag = isValue(now, i);
            if (flag == 0) continue;

            drawLine(now, i, 2);
            cnt_dfs++;
            core++;
            dfs(cnt_dfs);
            cnt_dfs--;
            core--;
            drawLine(now, i, 0);
        }
    }
}

int main()
{
    cin >> T;
    for (int tc = 1; tc < T + 1; tc++)
    {
        input();
        dfs(0);
        //        int pp = 100;
        cout << "#" << tc << " " << mini << '\n';
        V.clear();
    }
    return 0;
}