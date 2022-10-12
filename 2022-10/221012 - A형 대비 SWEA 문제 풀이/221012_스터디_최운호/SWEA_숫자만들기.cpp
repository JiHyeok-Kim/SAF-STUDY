#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int oper[4];
int nums[12];

vector<int> v;

void dfs(int val, int lev) {
	if (lev == n) {
		v.push_back(val);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (oper[i] == 0) continue;
		oper[i]--;
		if (i == 0) dfs(val + nums[lev], lev + 1);
		else if (i == 1) dfs(val - nums[lev], lev + 1);
		else if (i == 2) dfs(val * nums[lev], lev + 1);
		else dfs(val / nums[lev], lev + 1);
		oper[i]++;
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		for (int i = 0; i < 4; i++) {
			cin >> oper[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
		}

		dfs(nums[0], 1);
		
		sort(v.begin(), v.end());

		int answer = v[v.size() - 1] - v[0];

		cout << "#" << t << " " << answer << '\n';

		v.clear();
	}
	return 0;
}