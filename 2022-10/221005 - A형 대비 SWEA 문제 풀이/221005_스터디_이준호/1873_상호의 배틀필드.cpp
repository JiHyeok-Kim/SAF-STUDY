#include <iostream>
#include <cstring>
using namespace std;

int h, w, n;
string map[22];
string command;
int a, b, flag;

void init() {
    for (int i = 0; i < 22; i++) {
        map[i] = "";
    }
}

void shoot(int tank) {
    if (tank == 1 && a != 0) {
        for (int j = 1; j <= a; j++) {
            if (map[a - j][b] == '*') {
                map[a - j][b] = '.';
                break;
            }
            else if (map[a - j][b] == '#') break;
        }
    }
    else if (tank == 2 && a != h - 1) {
        for (int j = 1; j <= h - 1 - a; j++) {
            if (map[a + j][b] == '*') {
                map[a + j][b] = '.';
                break;
            }
            else if (map[a + j][b] == '#') break;
        }
    }
    else if (tank == 3 && b != 0) {
        for (int j = 1; j <= b; j++) {
            if (map[a][b - j] == '*') {
                map[a][b - j] = '.';
                break;
            }
            else if (map[a][b - j] == '#') break;
        }
    }
    else if (tank == 4 && b != w - 1) {
        for (int j = 1; j <= w - 1 - b; j++) {
            if (map[a][b + j] == '*') {
                map[a][b + j] = '.';
                break;
            }
            else if (map[a][b + j] == '#') break;
        }
    }
}

void solve(int tank) {
    for (int i = 0; i < n; i++) {
        if (command[i] == 'S') {
            shoot(tank);
        }
        else if (command[i] == 'U') {
            tank = 1;
            map[a][b] = '^';
            if (a == 0) continue;
            else if (map[a - 1][b] == '.') {
                map[a - 1][b] = '^';
                map[a][b] = '.';
                a -= 1;
            }
        }
        else if (command[i] == 'D') {
            tank = 2;
            map[a][b] = 'v';
            if (a == h - 1) continue;
            else if (map[a + 1][b] == '.') {
                map[a + 1][b] = 'v';
                map[a][b] = '.';
                a += 1;
            }
        }
        else if (command[i] == 'L') {
            tank = 3;
            map[a][b] = '<';
            if (b == 0) continue;
            else if (map[a][b - 1] == '.') {
                map[a][b - 1] = '<';
                map[a][b] = '.';
                b -= 1;
            }
        }
        else if (command[i] == 'R') {
            tank = 4;
            map[a][b] = '>';
            if (b == w - 1) continue;
            else if (map[a][b + 1] == '.') {
                map[a][b + 1] = '>';
                map[a][b] = '.';
                b += 1;
            }
        }
    }

    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen_s(new FILE*, "input.txt", "r", stdin);
    int tcCnt;
    cin >> tcCnt;
    for (int tc = 1; tc <= tcCnt; tc++) {
        cin >> h >> w;
        init();
        for (int i = 0; i < h; i++) {
            cin >> map[i];

            for (int x = 0; x < map[i].length(); x++) {
                if (map[i][x] == '^') { flag = 1; a = i; b = x; break; }
                else if (map[i][x] == 'v') { flag = 2; a = i; b = x; break; }
                else if (map[i][x] == '<') { flag = 3; a = i; b = x; break; }
                else if (map[i][x] == '>') { flag = 4; a = i; b = x; break; }
            }
        }
        cin >> n >> command;

        solve(flag);

        cout << "#" << tc << " ";
        for (int y = 0; y < h; y++) {
            cout << map[y] << "\n";
        }

    }
    return 0;
}