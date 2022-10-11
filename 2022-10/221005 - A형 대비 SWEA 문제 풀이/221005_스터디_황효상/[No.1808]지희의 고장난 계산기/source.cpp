#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <memory.h>


using namespace std;
vector<int> able_button;
vector<int> nums;
int cnt[1000001];
int T;
int target;

void make_nums(int base, int count) {
	for (int a = 0; a < able_button.size(); ++a) {
		int tmp = base * 10 + able_button[a];
		if (tmp > target)
			return;
		cnt[tmp] = count + 1;
		nums.push_back(tmp);
		make_nums(tmp, count + 1);
	}
}

void dfs(int base, int count) {
	for (int a = 0; a < nums.size(); ++a) {
		if (nums[a] == 0) continue;
		int tmp = base * nums[a];
		int total_cnt = count + cnt[nums[a]] + 1;
		if (tmp > target) return;
		if (cnt[tmp] == 0) {
			cnt[tmp] = total_cnt;
		}
		else {
			if (cnt[tmp] <= total_cnt)
				continue;
			else {
				cnt[tmp] = total_cnt;
			}
		}
		dfs(tmp, total_cnt);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

//	freopen("input.txt", "r", stdin);

	cin >> T;
	for (int t = 1; t <= T; ++t) {

		for (int a = 0; a < 10; ++a) {
			int tmp;
			cin >> tmp;
			if (tmp) {
				nums.push_back(a);
				able_button.push_back(a);
			}
		}
		cin >> target;
		for (int a = 0; a < able_button.size(); ++a) {
			if (able_button[a] == 0) continue;
			cnt[able_button[a]] = 1;
			make_nums(able_button[a],1);
		}

		if (cnt[target] != 0) {
			cout << "#" << t << " " << cnt[target]+1 << "\n";
		}
		else {
			sort(nums.begin(), nums.end());
			for (int a = 0; a < nums.size(); ++a) {
				if (nums[a] == 0) continue;
				dfs(nums[a], cnt[nums[a]]);
			}
			if (cnt[target] == 0) {
				cout << "#" << t << " " << -1 << "\n";
			}
			else {
				cout << "#" << t << " " << cnt[target]+1 << "\n";
			}
		}

		memset(cnt, 0, sizeof(cnt));
		nums.clear();
		able_button.clear();
	}

}
