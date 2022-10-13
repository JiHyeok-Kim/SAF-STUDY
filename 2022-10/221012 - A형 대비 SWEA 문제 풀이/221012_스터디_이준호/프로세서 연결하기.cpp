#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
int arr[12][12];
struct Node { int y, x; };
vector<Node> axis;

int directY[4] = { -1, 1, 0, 0 };
int directX[4] = { 0, 0, 1, -1 };

int maxChipCnt;
int minLineCnt;

int isFillLine(int nowY, int nowX, int bang) {
    int cnt = 0;

    for (int i = 1; i < 12; i++) {
        int ny = nowY + (directY[bang] * i);
        int nx = nowX + (directX[bang] * i);
        if (ny < 0 || nx < 0 || ny >= n || nx >= n) break;
        if (arr[ny][nx] != 0) return 0;
        cnt++;
    }
    return cnt;
}

void setFillLine(int nowY, int nowX, int bang, int beforeColor, int afterColor) {
    for (int i = 1; i < 12; i++) {
        int ny = nowY + (directY[bang] * i);
        int nx = nowX + (directX[bang] * i);
        if (ny < 0 || nx < 0 || ny >= n || nx >= n) break;
        if (arr[ny][nx] != beforeColor) break;
        arr[ny][nx] = afterColor;
    }
}

void run(int lev, int chipCnt, int lineCnt) {

    if (lev == axis.size()) {
        if (chipCnt > maxChipCnt) {
            maxChipCnt = chipCnt;
            minLineCnt = lineCnt;
        }
        else if (chipCnt == maxChipCnt && minLineCnt > lineCnt) {
            minLineCnt = lineCnt;
        }
        return;
    }

    int nowY = axis[lev].y;
    int nowX = axis[lev].x;

    for (int t = 0; t < 4; t++) {
        int cnt = isFillLine(nowY, nowX, t); //전선을 그을수 있을까?
        if (cnt == 0) continue; //못그으면 continue

        setFillLine(nowY, nowX, t, 0, 2); //선긋기
        run(lev + 1, chipCnt + 1, lineCnt + cnt); //재귀호출
        setFillLine(nowY, nowX, t, 2, 0); //선지우기
    }
    run(lev + 1, chipCnt, lineCnt);
}

void init() {
    memset(arr, 0, 12 * 12 * 4);
    axis.clear();
    maxChipCnt = 0;
    minLineCnt = 0;
}

int main() {
    freopen_s(new FILE *, "input.txt", "r", stdin);

    int tcCnt;
    cin >> tcCnt;
    for (int i = 1; i <= tcCnt; i++) {

        init();

        cin >> n;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                cin >> arr[y][x];

                if (arr[y][x] == 0) continue;
                if (y == 0 || y == n - 1 || x == 0 || x == n - 1) continue;
                axis.push_back({ y, x });
            }
        }

        run(0, 0, 0);
        cout << "#" << i << " " << minLineCnt << "\n";
    }


    return 0;
}