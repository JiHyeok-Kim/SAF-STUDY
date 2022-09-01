// SWEA 프로세서 연결하기
#include <iostream>
#include <vector>
using namespace std;
 
int T, N;
int MAP[15][15];
 
typedef struct {
    int y, x;
}CORE;
vector<CORE> v;
int maxi = -1, maxi_ret = 21e8;
 
const int dy[] = { 0,0,-1,1,0 }; // 5번 방향은 선택 안하고 다음 프로세서 탐색
const int dx[] = { -1,1,0,0,0 };
 
int isValid(CORE now, int dir) {
    int sum = 0;
 
    if (dir == 0) {
        for (int x = 0; x < now.x; ++x) {
            if (MAP[now.y][x] == 1 || MAP[now.y][x] == 2) return 0;
            sum++;
        }
    }
    if (dir == 1) {
        for (int x = now.x + 1; x < N; ++x) {
            if (MAP[now.y][x] == 1 || MAP[now.y][x] == 2) return 0;
            sum++;
        }
    }
    if (dir == 2) {
        for (int y = 0; y < now.y; ++y) {
            if (MAP[y][now.x] == 1 || MAP[y][now.x] == 2) return 0;
            sum++;
        }
    }
    if (dir == 3) {
        for (int y = now.y + 1; y < N; ++y) {
            if (MAP[y][now.x] == 1 || MAP[y][now.x] == 2) return 0;
            sum++;
        }
    }
    if (dir == 4) return 0;
 
    return sum;
}
 
void drawLine(CORE now, int dir) {
    if (dir == 0) {
        for (int x = 0; x < now.x; ++x) {
            MAP[now.y][x] = 2;
        }
    }
    if (dir == 1) {
        for (int x = now.x + 1; x < N; ++x) {
            MAP[now.y][x] = 2;
        }
    }
    if (dir == 2) {
        for (int y = 0; y < now.y; ++y) {
            MAP[y][now.x] = 2;
        }
    }
    if (dir == 3) {
        for (int y = now.y + 1; y < N; ++y) {
            MAP[y][now.x] = 2;
        }
    }
}
 
void eraseLine(CORE now, int dir) {
    if (dir == 0) {
        for (int x = 0; x < now.x; ++x) {
            MAP[now.y][x] = 0;
        }
    }
    if (dir == 1) {
        for (int x = now.x + 1; x < N; ++x) {
            MAP[now.y][x] = 0;
        }
    }
    if (dir == 2) {
        for (int y = 0; y < now.y; ++y) {
            MAP[y][now.x] = 0;
        }
    }
    if (dir == 3) {
        for (int y = now.y + 1; y < N; ++y) {
            MAP[y][now.x] = 0;
        }
    }
}
 
void DFS(int cnt, int line_sum, int pick_num) {
    if (cnt == v.size()) {
        if (maxi == pick_num) {
            maxi = pick_num;
            if (maxi_ret > line_sum) {
                maxi_ret = line_sum;
            }
        }
        else if (maxi < pick_num) {
            maxi = pick_num;
            maxi_ret = line_sum;
        }
 
        return;
    }
 
    CORE cur = v[cnt];
    for (int d = 0; d < 5; ++d) {
        int flag = isValid(cur, d);
        int plus = 1;
        if (flag > 0 || d == 4) {
            if (d == 4) plus = 0;
            drawLine(cur, d);
            DFS(cnt + 1, line_sum + flag, pick_num + plus);
            eraseLine(cur, d);
        }
    }
     
}
 
void init() {
    v.clear();
    maxi = -1, maxi_ret = 21e8;
}
 
int main()
{
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> N;
        init();
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < N; ++x) {
                cin >> MAP[y][x];
                if (y == 0 || y == N - 1 || x == 0 || x == N - 1) continue;
                if (MAP[y][x] == 0) continue;
                v.push_back({ y, x });
            }
        }
 
        DFS(0, 0, 1);
        cout << "#" << tc << " " << maxi_ret << "\n";
    }
    return 0;
}