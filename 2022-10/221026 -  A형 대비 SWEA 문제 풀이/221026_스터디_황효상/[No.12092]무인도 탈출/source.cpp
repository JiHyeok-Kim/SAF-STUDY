#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <stack>
#include <memory.h>
#include <algorithm>

using namespace std;

int boat[21][3];
int dp[20][3][1 << 20];
int N;
int maxi = 0;
void dfs(int num, int before_r, int before_c,int height) {
	int flag = 1;
	for (int a = 0; a < N; ++a) {
		int tmp = 1 << a;
		if (tmp & num) continue;
		int together = num | tmp;

		if ((boat[a][0] <= before_r && boat[a][1] <= before_c) || (boat[a][1] <= before_r && boat[a][0] <= before_c)) {
			int new_height = height + boat[a][2];
			if (new_height > dp[a][2][together]) {
				if (flag)
					flag = 0;
				dp[a][2][together] = new_height;
				dfs(together, boat[a][0], boat[a][1], new_height);
			}
		}
		if ((boat[a][0] <= before_r && boat[a][2] <= before_c)|| (boat[a][2] <= before_r && boat[a][0] <= before_c)) {
			int new_height = height + boat[a][1];
			if (new_height > dp[a][1][together]) {
				if (flag)
					flag = 0;
				dp[a][1][together] = new_height;
				dfs(together, boat[a][0], boat[a][2], new_height);
			}
		
		}
		if ((boat[a][1] <= before_r && boat[a][2] <= before_c)|| (boat[a][2] <= before_r && boat[a][1] <= before_c)) {
			int new_height = height + boat[a][0];
			if (new_height > dp[a][1][together]) {
				if (flag)
					flag = 0;
				dp[a][1][together] = new_height;
				dfs(together, boat[a][1], boat[a][2], new_height);
			}
		}

	}
	if (flag && maxi < height) {
		maxi = height;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> N;
		for (int a = 0; a < N; ++a) {
			for (int b = 0; b < 3; ++b) {
				cin >> boat[a][b];
			}
		}

		for (int a = 0; a < N; ++a) {
			dfs(1 << a, boat[a][0], boat[a][1], boat[a][2]);
			dfs(1 << a, boat[a][0], boat[a][2], boat[a][1]);
			dfs(1 << a, boat[a][1], boat[a][2], boat[a][0]);
		}
		cout << "#"<<t<<" "<<maxi << "\n";
		maxi = 0;
		memset(dp, 0, sizeof(dp));
	}
}
