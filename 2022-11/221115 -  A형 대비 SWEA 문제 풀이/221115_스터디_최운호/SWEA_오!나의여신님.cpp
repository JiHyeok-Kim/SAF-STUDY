#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
 
struct Info {
    int y, x;
    int time;
};
int N, M;
char map[60][60];
int devilTime[60][60];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
int startY, startX, endY, endX;
vector<Info> devils;
 
void init()
{
    N = M = 0;
    memset(map, 0, sizeof(map));
    startY = startX = endY = endX = 0;
    devils.clear();
}
 
void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'S')
            {
                startY = i;
                startX = j;
            }
            else if (map[i][j] == 'D')
            {
                endY = i;
                endX = j;
            }
            else if (map[i][j] == '*')
                devils.push_back({ i, j, 0 });
        }
}
 
void devilRun()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            devilTime[i][j] = 21e8;
 
    queue<Info> q;
 
    for (int i = 0; i < devils.size(); i++) {
        q.push({ devils[i].y, devils[i].x, devils[i].time });
        devilTime[devils[i].y][devils[i].x] = 0;
    }
 
    while (!q.empty())
    {
        Info now = q.front();
        q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
 
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (map[ny][nx] == 'X' || map[ny][nx] == 'D') continue;
            if (devilTime[ny][nx] <= devilTime[now.y][now.x] + 1) continue;
 
            devilTime[ny][nx] = devilTime[now.y][now.x] + 1;
            q.push({ ny, nx });
        }
    }
}
 
int sRun()
{
    queue<Info> q;
    int used[60][60] = { 0, };
 
    used[startY][startX] = 1;
    q.push({ startY, startX, 0 });
 
    while (!q.empty())
    {
        Info now = q.front();
        q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
 
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (used[ny][nx] == 1) continue;
            if (map[ny][nx] == 'X') continue;
            if (devilTime[ny][nx] <= now.time + 1) continue;
            if (ny == endY && nx == endX) return now.time + 1;
 
            used[ny][nx] = 1;
            q.push({ ny, nx, now.time + 1 });
        }
    }
 
    return -1;
}
 
void solve()
{
    int tc;
    cin >> tc;
 
    for (int t = 1; t <= tc; t++)
    {
        init();
        input();
        devilRun();
        int ret = sRun();
        if (ret == -1)
        {
            cout << "#" << t << " GAME OVER" << "\n";
            continue;
        }
        cout << "#" << t << " " << ret << "\n";
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
 
    solve();
 
    return 0;
}