#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<math.h>

using namespace std;


struct Node {
    int x;
    int y;
};
int T, N, W, H;
vector<vector<int>> map(16, vector<int>(16, 0));
int mp[16][16];

int block = 0;
int mini = 21e8;
int mov[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int path[5];

int pang(int x, int y) {

    int cnt = 1;
    if (mp[x][y] == 1) {
        mp[x][y] = 0;
    }
    else {
        int rang = mp[x][y];
        mp[x][y] = 0;
        for (int a = 0; a < rang; ++a) {
            for (int b = 0; b < 4; ++b) {
                int xx = x + mov[b][0] * a;
                int yy = y + mov[b][1] * a;

                if (xx >= 0 && xx < H && yy >= 0 && yy < W && mp[xx][yy] >0) {
                    cnt += pang(xx, yy);
                }
            }
        }
    }

    return cnt;
}

void cleaner() {

    while (1) {
        int checker = 0;
        for (int a = H - 1; a > 0; --a) {
            for (int b = 0; b < W; ++b) {
                if (mp[a][b] == 0 && mp[a - 1][b] != 0) {
                    mp[a][b] = mp[a - 1][b];
                    mp[a - 1][b] = 0;
                    if (checker == 0)
                        checker = 1;
                }
            }
        }
        if (checker == 0)
            return;
    }
}

void down(int cnt, int boom_count) {
    if (cnt == N) {
        cnt = 0;
        for (int a = 0; a < H; ++a) {
            for (int b = 0; b < W; ++b) {
                if (mp[a][b] != 0)
                    ++cnt;
            }
        }
        if (cnt < mini)
            mini = cnt;
        return;
    }

    int iidx = -1;
    for (int a = 0; a < H; ++a) {
        if (mp[a][path[cnt]] != 0) {
            iidx = a;
            break;
        }
    }
    if (iidx == -1)
        return;
       
    boom_count += pang(iidx, path[cnt]);


    cleaner();
    
    down(cnt + 1, boom_count);

}

void choice(int cnt) {
    if (cnt == N) {
        for (int a = 0; a < H; ++a) {
            for (int b = 0; b < W; ++b) {
                mp[a][b] = map[a][b];
            }
        }
        down(0,0);
    }
    else {
        for (int a = 0; a < W; ++a) {
            path[cnt] = a;
            choice(cnt + 1);
        }
    }
}
void solve() {

    for (int a = 0; a < W; ++a) {
        path[0] = a;
        choice(1);
    }
}
void input() {
    cin >> T;

    for (int a = 0; a < T; ++a) {
        cin >> N >> W >> H;
        for (int b = 0; b < H; ++b) {
            for (int c = 0; c < W; ++c) {
                cin >> map[b][c];
                if (map[b][c] != 0)
                    ++block;
            }
        }
        solve();
        cout << "#" << a + 1 << " ";
        if (mini == 21e8)
            cout << 0 << "\n";
        else
            cout << mini << "\n";
        for (int a = 0; a < H; ++a) {
            for (int b = 0; b < W; ++b)
                map[a][b] = 0;
        }
        block = 0;
        mini = 21e8;
    }
}
int main()
{
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    input();

    return 0;

}
