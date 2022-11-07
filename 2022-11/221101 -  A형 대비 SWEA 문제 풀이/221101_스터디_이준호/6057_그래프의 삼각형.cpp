#include <iostream>
using namespace std;
 
int ans, n, m;
int map[51][51];
int used[51];
int path[3];
 
void init() {
    ans = 0;
    for (int i = 0; i < 51; i++) {
        for (int j = 0; j < 51; j++) {
            map[i][j] = 0;
        }
    }
}
void input() {
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
}
 
void isTri() {
    if (map[path[0]][path[1]] == 1 
        && map[path[1]][path[2]] == 1 && map[path[0]][path[2]] == 1) {
        ans++;
    }
}
 
void dfs(int lev, int start) {
    if (lev == 3) {
        isTri();
        return;
    }
    for (int i = start; i <= n; i++) {
        if (used[i] == 1) continue;
        used[i] = 1;
        path[lev] = i;
        dfs(lev + 1, i + 1);
        path[lev] = 0;
        used[i] = 0;
    }
}
 
int main()
{
    //freopen_s(new FILE*, "input.txt", "r", stdin);
    int tcCnt;
    cin >> tcCnt;
    for (int tc = 1; tc <= tcCnt; tc++) {
        init();
        input();
        dfs(0, 1);
        cout << "#" << tc << " " << ans << "\n";
    }
 
    return 0;
}