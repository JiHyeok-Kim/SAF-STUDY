#include <iostream>
using namespace std;

long long n, m;
long long arr[100001];

long long cutCount(long long tar) {
	long long cnt = 0;
	for (long long i = 0; i < n; i++) {
		cnt += (tar / arr[i]);
	}
	return cnt;
}

long long bs(long long s, long long e) {
	long long last = 0;
	while (s <= e) {
		long long mid = (s + e) / 2;
		long long cc = cutCount(mid);

		if (cc >= m) {
			last = mid;
			e = mid - 1;
		}
		else if (cc < m) {
			s = mid + 1;
		}
	}
	return last;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ret = bs(1, 21e8);
	cout << ret;
}