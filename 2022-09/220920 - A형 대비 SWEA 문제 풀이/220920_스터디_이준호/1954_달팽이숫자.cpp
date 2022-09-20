#include <iostream>
using namespace std;
 
int n;
int arr[11][11];
int ditY[4] = { 0,1,0,-1 };
int ditX[4] = { 1,0,-1,0 };
 
void init() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            arr[y][x] = 0;
        }
    }
}
 
void input() {
    int dir = 0;
    int x = 0;
    int y = 0;
    int nx, ny;
 
    for (int i = 1; i <= n * n; i++) {
        arr[y][x] = i;
        ny = y + ditY[dir];
        nx = x + ditX[dir];
         
        if (ny < 0 || nx < 0 || ny >= n || nx >= n || arr[ny][nx] != 0) {
            dir = (dir + 1) % 4;
        }
 
        y += ditY[dir];
        x += ditX[dir];
    }
 
}
 
 
int main() {
    int tcCnt;
    cin >> tcCnt;
    for (int tc = 1; tc <= tcCnt; tc++) {
        cin >> n;
        init();
        input();
 
        cout << "#" << tc << "\n";
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                cout << arr[y][x] << " ";
            }
            cout << "\n";
        }
 
    }
    return 0;
}