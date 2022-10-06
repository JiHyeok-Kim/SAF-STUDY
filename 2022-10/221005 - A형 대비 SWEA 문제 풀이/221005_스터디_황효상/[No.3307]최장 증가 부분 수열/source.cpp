#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <memory.h>
using namespace std;


int T;
int N;
int nums[1001];
vector<int> cnt;

int bs(int num) {
	int s = 0;
	int e = cnt.size() - 1;
	int idx = -1;
	while (s <= e) {
		int mid = (s + e)/2;

		if (cnt[mid] >= num) {
			idx = mid;
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	return idx;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
//	freopen("input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> N;
		for (int a = 0; a < N; ++a) {
			cin >> nums[a];
		}
		cnt.push_back(nums[0]);
		for (int a = 1; a < N; ++a) {
			int idx = bs(nums[a]);
			if (idx == -1) {
				cnt.push_back(nums[a]);
			}
			else {
				cnt[idx] = nums[a];
			}
		}
		cout <<"#"<<t<<" "<< cnt.size() << "\n";
		cnt.clear();
		memset(nums, 0, sizeof(nums));

	}
	
	return 0;
}
