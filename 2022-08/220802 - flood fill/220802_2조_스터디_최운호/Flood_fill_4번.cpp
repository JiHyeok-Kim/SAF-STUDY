#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[101][101];
int used[101][101];

struct knight {
    int y;
    int x;
    int move;
};

queue<knight> q;

int main() {
    int h, w;
    cin >> h >> w;
    int k_y, k_x, tar_y, tar_x;
    cin >> k_y >> k_x >> tar_y >> tar_x;

    q.push({ k_y, k_x, 0 });
    used[k_y][k_x] = 1;

    int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
    int dy[8] = { -2,-1,1,2,-2,-1,1,2 };

    while (!q.empty()) {
        knight now = q.front();
        q.pop();

        if (now.y == tar_y && now.x == tar_x) {
            cout << now.move;
            break;
        }

        for (int i = 0; i < 8; i++) {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (nx >= 0 && ny >= 0 && nx < w && ny < h) {
                if (used[ny][nx]) continue;
                used[ny][nx] = 1;
                q.push({ ny, nx, now.move + 1 });
            }
        }
    }

    return 0;
}