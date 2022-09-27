#include <iostream>
#include <string>
#include <queue>
using namespace std;
 
struct pos {
    int y;
    int x;
    int cost;
};
 
int map[100][100];
int dist[100][100];
 
int n;
 
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };
 
void bfs() {
    queue<pos> q;
    q.push({ 0,0,0 });
    dist[0][0] = 0;
 
    while (!q.empty()) {
        pos now = q.front();
        q.pop();
 
        for (int i = 0; i < 4; i++) {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (dist[ny][nx] <= map[ny][nx] + dist[now.y][now.x]) continue;
            dist[ny][nx] = map[ny][nx] + dist[now.y][now.x];
            q.push({ ny,nx,dist[ny][nx] });
        }
    }
}
 
int main() {
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            for (int j = 0; j < n; j++) {
                map[i][j] = str[j] - '0';
                dist[i][j] = 21e8;
            }
        }
 
        bfs();
         
        int answer = dist[n - 1][n - 1];
 
        cout << "#" << t << " " << answer << '\n';
    }
    return 0;
}