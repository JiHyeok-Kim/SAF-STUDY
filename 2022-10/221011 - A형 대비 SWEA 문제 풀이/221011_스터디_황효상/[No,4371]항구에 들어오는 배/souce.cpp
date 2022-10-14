#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

int T, N;
long long nums[5001];
bool checker[5001];
void init() {
	memset(nums, 0, sizeof(nums));
	memset(checker, 0, sizeof(checker));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("Input.txt", "r", stdin);

	cin >> T;

	for (int t = 1; t <= T; ++t) {
		cin >> N;
		init();
		for (int a = 0; a < N; ++a) {
			cin >> nums[a];
			nums[a] -= 1;
		}
		int cnt = 0;
		int total = 1;
		for (int a = 1; a < N; ++a) {
			if(checker[a]==0){
				long long target = nums[a];
				++cnt;
				for (int b = a; b < N; ++b) {
					if (nums[b] % target == 0 && checker[b] == 0) {
						checker[b] = 1;
						++total;
					}
				}
			}
			if (total == N) {
				break;
			}
		}
		cout << "#"<<t<<" " <<cnt<<"\n";
	}


	return 0;
}
