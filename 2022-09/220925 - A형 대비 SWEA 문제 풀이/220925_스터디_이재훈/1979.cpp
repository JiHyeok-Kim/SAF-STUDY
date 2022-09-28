#include <iostream>
 
#include<queue>
 
#include<string>
 
#include<stdio.h>
 
#include<algorithm>
 
#include<queue>
using namespace std;
 
int divx[] = { 0,1 };
int divy[] = { 1,0 };
int N, K;
int arr[15][15];
 
int dfs1(int row, int col, int lev) {
    int next_row = row + divx[1];
    int next_col = col + divy[1];
    if (arr[next_row][next_col] != 1)return lev;
    if (next_row >= N)return lev;
    dfs1(next_row, next_col, lev + 1);
 
}
int dfs2(int row, int col, int lev) {
 
    int next_row = row + divx[0];
    int next_col = col + divy[0];
    if (arr[next_row][next_col] != 1)return lev;
    if (next_col >= N)return lev;
    dfs2(next_row, next_col, lev + 1);
 
 
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
 
    //freopen_s(new FILE*, "input.txt", "r", stdin);
 
    int T;
    cin >> T;
 
 
 
    for (int cas = 1; cas <= T; cas++) {
        int cnt2 = 0;
        cout << "#" << cas << " ";
 
        cin >> N >> K;
 
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                cin >> arr[row][col];
            }
        }
        //밑으로 진행
        for (int col = 0; col < N; col++) {
            for (int row = 0; row < N; row++) {
                if (arr[row][col] == 1) {
                    int t = dfs1(row, col, 1);
                    if (t == K) {
                        cnt2++;
                        row = row + K;
                    }
                    if (t > K) {
                        row = row + t;
                    }
 
                }
            }
        }
        // 옆으로 진행
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                if (arr[row][col] == 1) {
                    int t = dfs2(row, col, 1);
                    if (t == K)
                    {
                        cnt2++;
                        col = col + K;
                    }
                    if (t > K) {
                        col = col + t;
                    }
                }
            }
        }
 
        cout << cnt2 << "\n";
    }
 
}
