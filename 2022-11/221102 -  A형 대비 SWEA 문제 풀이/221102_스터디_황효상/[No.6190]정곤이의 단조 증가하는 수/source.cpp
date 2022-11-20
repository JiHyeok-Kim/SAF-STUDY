#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;


int nums[1001];
int N, T;

int check(int tmp) {
	int ori = tmp;
	int target = 10;
	int before = 9;
	while (tmp != 0) {
		int nowNum = tmp % target;
		if (before >= nowNum) {
			before = nowNum;
			tmp = tmp/10;
		}
		else
			return -1;
	}
	return ori;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);

	cin >> T;
	for (int t = 1; t <= T; ++t) {
		memset(nums, 0, sizeof(nums));
		cin >> N;
		for (int a = 0; a < N; ++a) {
			cin >> nums[a];
		}
		int ans = -1;
		for (int a = 0; a < N; ++a) {
			for (int b = a+1; b < N; ++b) {
				ans = max(ans, check(nums[a] * nums[b]));
			}
		}
		cout << "#"<<t<<" " <<ans<<"\n";
	}
	
	return 0;
}
