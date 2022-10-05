#include <iostream>
using namespace std;
int H, W, N;
char map[25][25];
char cmd[110];
pair<int, int> tank;
int drY[4] = { -1,1,0,0 };
int drX[4] = { 0,0,-1,1 };
void input() {

    cin >> H >> W;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            cin >> map[y][x];
            if (map[y][x] == '>' || map[y][x] == '<' || map[y][x] == '^' || map[y][x] == 'v') {
                tank.first = y;
                tank.second = x;
            }
        }
    }
    cin >> N;
    for (int i = 0; i < N; i++) cin >> cmd[i];
}
void up() {
    map[tank.first][tank.second] = '^';
    int ny = tank.first + drY[0];
    int nx = tank.second + drX[0];
    if (ny < 0 || nx < 0 || ny >= H || nx >= W || map[ny][nx] != '.') return;
    map[tank.first][tank.second] = '.';
    tank.first = ny;
    tank.second = nx;
    map[tank.first][tank.second] = '^';
}
void down() {
    map[tank.first][tank.second] = 'v';
    int ny = tank.first + drY[1];
    int nx = tank.second + drX[1];
    if (ny < 0 || nx < 0 || ny >= H || nx >= W || map[ny][nx] != '.') return;
    map[tank.first][tank.second] = '.';
    tank.first = ny;
    tank.second = nx;
    map[tank.first][tank.second] = 'v';
}void left1() {
    map[tank.first][tank.second] = '<';
    int ny = tank.first + drY[2];
    int nx = tank.second + drX[2];
    if (ny < 0 || nx < 0 || ny >= H || nx >= W || map[ny][nx] != '.') return;
    map[tank.first][tank.second] = '.';
    tank.first = ny;
    tank.second = nx;
    map[tank.first][tank.second] = '<';
}void right1() {
    map[tank.first][tank.second] = '>';
    int ny = tank.first + drY[3];
    int nx = tank.second + drX[3];
    if (ny < 0 || nx < 0 || ny >= H || nx >= W || map[ny][nx] != '.') return;
    map[tank.first][tank.second] = '.';
    tank.first = ny;
    tank.second = nx;
    map[tank.first][tank.second] = '>';
}
void shoot() {
    int dir = 0;
    if (map[tank.first][tank.second] == '^') dir = 0;
    if (map[tank.first][tank.second] == 'v') dir = 1;
    if (map[tank.first][tank.second] == '<') dir = 2;
    if (map[tank.first][tank.second] == '>') dir = 3;

    for (int i = 1; i < 20; i++) {
        int ny = tank.first + drY[dir] * i;
        int nx = tank.second + drX[dir] * i;
        if (ny < 0 || nx < 0 || ny >= H || nx >= W) break;
        if (map[ny][nx] == '#') break;
        if (map[ny][nx] == '*') {
            map[ny][nx] = '.';
            break;
        }
    }
}
void solution() {
    for (int i = 0; i < N; i++) {
        if (cmd[i] == 'U') up();
        else if (cmd[i] == 'D') down();
        else if (cmd[i] == 'L') left1();
        else if (cmd[i] == 'R') right1();
        else if (cmd[i] == 'S') shoot();
        int a = 1;
    }
}
void output(int t) {
    cout << "#" << t << " ";
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            cout << map[y][x];
        }
        cout << "\n";
    }
}
void solve() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        input();
        solution();
        output(t);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen_s(new FILE*, "input.txt", "r", stdin);
    solve();
    return 0;
}