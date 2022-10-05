#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

int T;
int month[13];
int cost[4];
int dp[13][4];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		memset(month, 0, sizeof(month));
		memset(cost, 0, sizeof(cost));
		memset(dp, 0, sizeof(dp));
		cin >> cost[0] >> cost[1] >> cost[2] >> cost[3];
		for (int a = 1; a <= 12; ++a) {
			cin >> month[a];
		}
      for(int b =0;b < 4; ++b){
        if(b==0)
          dp[1][0] = month[1]*cost[b];
        else
          dp[a][b] = cost[b];
      }

		for (int a = 2; a <= 12; ++a) {
			int mini = min(dp[a - 1][0], min(dp[a - 1][1], dp[1][3]));
			if (a >=4) mini = min(mini, dp[a - 3][2]);
      for(int b =0;b < 3; ++b){
        if(b==0)
          dp[a][0] = mini+ month[a]*cost[b];
        else
          dp[a][b] = mini+cost[b];
      }
		}
		int ans = min(dp[12][0], min(dp[12][1], min(dp[10][2], dp[1][3])));
		cout << "#"<<t<<" "<<ans << "\n";
	}
	
	return 0;
}
