#include <iostream>
#include <cstring>
using namespace std;

int N, ans;
char map[300][301];
int directY[8] = { -1,-1,-1,0,0,1,1,1 };
int directX[8] = { -1,0,1,-1,1,-1,0,1 };

void init()
{
    ans = 0;
    for (int y = 0; y < 300; y++) {
        for (int x = 0; x < 301; x++) {
            map[y][x] = ' ';
        }
    }
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> map[i];
    }

    return;
}

int isValid(int ty, int tx)
{
    int num = 0;
    for (int i = 0; i < 8; i++)
    {
        int dy = ty + directY[i];
        int dx = tx + directX[i];
        if (dy < 0 || dx < 0 || dy >= N || dx >= N) continue;
        if (map[dy][dx] == '*') num++;
    }
    if (num > 0) return 0;
    else return 1;
}

void isPang(int ty, int tx)
{
    map[ty][tx] = '0';
    for (int i = 0; i < 8; i++)
    {
        int dy = ty + directY[i];
        int dx = tx + directX[i];
        if (dy < 0 || dx < 0 || dy >= N || dx >= N) continue;
        if (map[dy][dx] != '.') continue;
        if (isValid(dy, dx) == 1) isPang(dy, dx);
        else map[dy][dx] = '#';
    }

    return;
}

void click()
{
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (map[y][x] == '*') continue;
            if (map[y][x] == '0') continue;
            if (map[y][x] == '#') continue;
            if (isValid(y, x) == 0) continue;
            isPang(y, x);
            ans++;
        }
    }

    return;
}

int cnt()
{
    int cnt = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (map[y][x] == '.') cnt++;
        }
    }

    return cnt;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {

        init();
        click();
        ans += cnt();

        cout << "#" << tc << " " << ans << "\n";
    }

    return 0;
}