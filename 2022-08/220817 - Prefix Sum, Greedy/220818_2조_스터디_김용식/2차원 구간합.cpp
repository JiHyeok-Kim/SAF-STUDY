#include <iostream>
#include <vector>
using namespace std;
int dy[3] = { -1,0,-1 };
int dx[3] = { 0,-1,-1 };
int Arr[1011][1012] = { 0 };
int Sum[1011][1011] = { 0 };
int N, M;

void find(int y, int x) {
    Sum[y][x] += Arr[y][x];
    for (int i = 0; i < 3; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny <= 0 || nx <= 0 || nx > N || ny > N)continue;
        if (i == 2) {
            Sum[y][x] -= Sum[ny][nx];
            return;
        }
        Sum[y][x] += Sum[ny][nx];
    }
    return;
}

void result(int y1, int x1, int y2, int x2) {
    int sum = 0;
    sum = Sum[y2][x2] - Sum[y2][(x1)-1] - Sum[(y1)-1][x2] + Sum[(y1)-1][(x1)-1];
    cout << sum << '\n';
}

int main() {

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> Arr[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            find(i, j);
        }
    }

    for (int i = 0; i < M; i++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        result((y1), (x1), (y2), (x2));
    }

    return 0;
}