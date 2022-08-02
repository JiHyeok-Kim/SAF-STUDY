#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[101][101];
int used[101][101];

struct horse {
    int y;
    int x;
    int move;
};

queue<horse> q;

int main() {
    int h, w, r, c;
    cin >> h >> w >> r >> c;

    int blue_y, blue_x;
    cin >> blue_y >> blue_x;

    int cnt;
    cin >> cnt;

    for (int i = 0; i < cnt; i++) {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
    }

    q.push({ r,c, 0 });
    used[r][c] = 1;

    int dx[8] = { 2,3,3,2,-2,-3,-3,-2 };
    int dy[8] = { -3,-2,2,3,3,2,-2,-3 };

    int flag = 0;
    int answer;

    while (!q.empty()) {
        horse now = q.front();
        q.pop();

        if (now.y == blue_y && now.x == blue_x) {
            flag = 1;
            answer = now.move;
            break;
        }

        for (int i = 0; i < 8; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < w && ny < h) {
                if (map[ny][nx] == 0 && used[ny][nx] == 0) {
                    used[ny][nx] = 1;
                    q.push({ ny, nx, now.move + 1 });
                }
            }
        }

    }

    if (flag) cout << answer;
    else cout << -1;

    return 0;

}