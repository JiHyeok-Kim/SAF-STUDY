#include <iostream>
using namespace std;

int store[110000], N, M;

int bs(int s, int e) {
	long long minSec = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		long long manCnt = 0;
		for (int i = 0; i < N; i++) {
			manCnt += mid / store[i];
		}
		if (manCnt >= M) {
			minSec = mid;
			e = mid - 1;
		}
		else s = mid + 1;
	}
	return minSec;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> store[i];
	int ans = bs(0, 1000000000);
	cout << ans;
	return 0;
}