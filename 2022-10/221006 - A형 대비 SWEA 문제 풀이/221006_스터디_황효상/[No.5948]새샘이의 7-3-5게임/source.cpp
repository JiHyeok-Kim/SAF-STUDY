#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <memory.h>

using namespace std;
int T;
vector<int> nums;
vector<int> tmp;
bool used[301];
bool check[8];

void dfs(int deep,int sum, int idx) {
	if (deep == 3) {
		if (used[sum] == 0) {
			used[sum] = 1;
			tmp.push_back(sum);
		}
		return;
	}

	for (int a = idx + 1; a < nums.size(); ++a) {
		if (check[a] == 0) {
			check[a] = 1;
			dfs(deep + 1, sum + nums[a], a);
			check[a] = 0;
		}
	}


}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		for (int a = 0; a < 7; ++a) {
			int tmp;
			cin >> tmp;
			nums.push_back(tmp);
		}
		for (int a = 0; a < nums.size(); ++a) {
			check[a] = 1;
			dfs(1, nums[a],0);
			check[a] = 0;
		}
		sort(tmp.begin(), tmp.end(),greater<int>());
		cout << "#" << t << " " << tmp[4] << "\n";
		nums.clear();
		tmp.clear();
		memset(used, 0, sizeof(used));
        memset(check,0,sizeof(check));
	}
}
