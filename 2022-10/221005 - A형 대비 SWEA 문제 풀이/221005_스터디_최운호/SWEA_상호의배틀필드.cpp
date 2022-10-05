#include <iostream>
#include <string>
using namespace std;
 
char map[20][20];
int H, W, n;
char command[100];
int state;
int tY, tX;
 
int dy[5] = { 0,-1,1,0,0 };
int dx[5] = { 0,0,0,-1,1 };
 
void getState()
{
    if (map[tY][tX] == '^') state = 1;
    else if (map[tY][tX] == 'v') state = 2;
    else if (map[tY][tX] == '<') state = 3;
    else if (map[tY][tX] == '>') state = 4;
}
 
void shot() {
    if (state == 1) {
        for (int i = tY - 1; i >= 0; i--) {
            if (map[i][tX] == '#') break;
            else if (map[i][tX] == '*') {
                map[i][tX] = '.';
                break;
            }
        }
    }
    else if (state == 2) {
        for (int i = tY + 1; i < H; i++) {
            if (map[i][tX] == '#') break;
            else if (map[i][tX] == '*') {
                map[i][tX] = '.';
                break;
            }
        }
    }
    else if (state == 3) {
        for (int i = tX - 1; i >= 0; i--) {
            if (map[tY][i] == '#') break;
            else if (map[tY][i] == '*') {
                map[tY][i] = '.';
                break;
            }
        }
    }
    else if (state == 4) {
        for (int i = tX + 1; i < W; i++) {
            if (map[tY][i] == '#') break;
            else if (map[tY][i] == '*') {
                map[tY][i] = '.';
                break;
            }
        }
    }
}
 
void move(char ch)
{
    if (ch == 'U') map[tY][tX] = '^';
    else if (ch == 'D') map[tY][tX] = 'v';
    else if (ch == 'L') map[tY][tX] = '<';
    else if (ch == 'R') map[tY][tX] = '>';
 
    getState();
 
    int ny = tY + dy[state];
    int nx = tX + dx[state];
 
    if (ny < 0 || nx < 0 || ny >= H || nx >= W) return;
    if (map[ny][nx] != '.') return;
 
    map[ny][nx] = map[tY][tX];
    map[tY][tX] = '.';
    tY = ny;
    tX = nx;
}
 
void run()
{
    for (int i = 0; i < n; i++) {
        if (command[i] == 'S') {
            shot();
            continue;
        }
        move(command[i]);
    }
}
 
int main()
{
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cin >> H >> W;
        for (int i = 0; i < H; i++) {
            string str;
            cin >> str;
            for (int j = 0; j < W; j++) {
                map[i][j] = str[j];
                if (map[i][j] == '^' || map[i][j] == '<' || map[i][j] == '>' || map[i][j] == 'v') {
                    tY = i;
                    tX = j;
                    getState();
                }
            }
        }
        cin >> n;
        string cmd;
        cin >> cmd;
        for (int i = 0; i < n; i++) {
            command[i] = cmd[i];
        }
 
        run();
 
        cout << "#" << t << " ";
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cout << map[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}