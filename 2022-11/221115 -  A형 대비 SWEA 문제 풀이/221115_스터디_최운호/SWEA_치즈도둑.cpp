#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
 
int map[100][100];
int N;
int answer = 0;
int maxVal = 0;
 
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
 
void init()
{
    cin >> N;
    answer = 0;
    maxVal = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            maxVal = max(maxVal, map[i][j]);
        }
    }
}
 
int getCheese(int d) {
    struct Node {
        int y;
        int x;
    };
    int result = 0;
 
    bool used[100][100] = { false };
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] <= d) continue;
            if (used[i][j]) continue;
            used[i][j] = true;
 
            queue<Node> q;
            q.push({ i,j });
 
            result++;
 
            while (!q.empty())
            {
                Node now = q.front();
                q.pop();
 
                for (int dir = 0; dir < 4; dir++) {
                    int ny = now.y + dy[dir];
                    int nx = now.x + dx[dir];
                    if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
                    if (map[ny][nx] <= d) continue;
                    if (used[ny][nx]) continue;
                    used[ny][nx] = true;
                    q.push({ ny,nx });
                }
            }
        }
    }
 
    return result;
}
 
void solve()
{
    for (int i = 0; i <= maxVal; i++) {
        int ret = getCheese(i);
        answer = max(answer, ret);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        init();
 
        solve();
 
        cout << "#" << t << " " << answer << '\n';
    }
    return 0;
}