#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <stack>
#include <memory.h>
#include <algorithm>
 
using namespace std;
 
int T;
int N, K;
int V[101];
int C[101];
int dp[101][1001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin); 
    cin >> T;
    for(int t = 1; t<= T; ++t){
        cin >> N >> K;
        for (int a = 1; a <= N; ++a) {
            cin >> V[a] >> C[a];
        }
 
        for (int a = 1; a <= N; ++a) {
            for (int b = 0; b < V[a]; ++b)
                dp[a][b] = dp[a - 1][b];
            for (int b = 0; b <= K; ++b) {
                int newV = b + V[a];
                if (newV > K) continue;
                dp[a][newV] =  max(dp[a - 1][newV], dp[a - 1][b] + C[a]);
            }
        }
        cout << "#"<<t<<" "<<dp[N][K]<<"\n";
        memset(dp,0,sizeof(dp));
    }
}
