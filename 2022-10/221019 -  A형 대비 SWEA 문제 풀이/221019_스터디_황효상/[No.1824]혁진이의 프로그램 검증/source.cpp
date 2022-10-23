#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>>
#include <unordered_map>
using namespace std;

int T, R, C;
char code[22][22];
int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
unordered_map<char, int> mp;
bool visited[22][22][4][16];
bool flag = 0;


struct Node {
    int x;
    int y;

};

void XY(int *nx, int *ny) {
    int x = *nx;
    int y = *ny;
    if (x < 0) {
        x = R - 1;
    }
    else if (x >= R) {
        x = 0;
    }
    else if (y < 0) {
        y = C - 1;
    }
    else if (y >= C) {
        y = 0;
    }

    *nx = x;
    *ny = y;
}
void run(int x,int y, int arrow,int num) {
    if (flag)
        return;
    if (code[x][y] == '_') {
        if (num == 0) {
            arrow = 1;
        }
        else {
            arrow = 3;
        }
    }
    else if (code[x][y] == '|') {
        if (num == 0) {
            arrow = 2;
        }
        else {
            arrow = 0;
        }
    }
    else if (code[x][y] == '?') {
        arrow = -1;
    }
    else if (code[x][y] == '@') {
        flag = 1;
        return;
    }
    else if (code[x][y] >= '0' && code[x][y] <= '9') {
        num = code[x][y] - '0';
    }
    else if(code[x][y] == '^' || code[x][y] == '>' || code[x][y] == 'v' || code[x][y] == '<'){
        if(mp.count(code[x][y]) != 0)
            arrow = mp[code[x][y]];
    }
    else if (code[x][y] == '+') {
        ++num;
        if(num >= 16)
            num = 0;
    }
    else if (code[x][y] == '-') {
        --num;
        if (num < 0)
            num = 15;
    }

    if (arrow == -1) {
    if (flag) return;
        for (int a = 0; a < 4; ++a) {
            int nx = x + mov[a][0];
            int ny = y + mov[a][1];
            XY(&nx, &ny);
            if (visited[nx][ny][a][num] == 0) {
                visited[nx][ny][a][num] = 1;
                run(nx, ny, a, num);
            }
        }
    }
    else {
        int nx = x + mov[arrow][0];
        int ny = y + mov[arrow][1];

        XY(&nx, &ny);

        if (visited[nx][ny][arrow][num] == 0) {
            visited[nx][ny][arrow][num] = 1;
            run(nx, ny, arrow, num);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("Input.txt", "r", stdin);
    mp['^'] = 0;
    mp['>'] = 1;
    mp['v'] = 2;
    mp['<'] = 3;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> R >> C;
        flag = 0;
        int check = 0;
        memset(code, 0, sizeof(code));
        memset(visited, 0, sizeof(visited));
        for (int a = 0; a < R; ++a) {
            for (int b = 0; b < C; ++b) {
                cin >> code[a][b];
                if (code[a][b] == '@')
                    check = 1;
            }
        }
        if (check) {
            visited[0][0][1][0] = 1;
            run(0, 0, 1, 0);
        }

        if (flag) {
            cout << "#"<<t<<" YES\n";

        }
        else {
            cout << "#"<<t<<" NO\n";
        }
    }


    return 0;
}
