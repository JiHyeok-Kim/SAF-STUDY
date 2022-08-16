#include <iostream>
using namespace std;

long long n;
long long maxVal, maxGop;

void go(long long s, long long e) {
	if (s > e) return;
	long long mid = (s + e) / 2;
	long long gop = mid * mid;

	if (gop <= n && maxGop <= gop) {
		maxGop = gop;
		maxVal = mid;
	}

	if (gop < n) go(mid + 1, e);
	if (gop > n) go(s, mid - 1);
}

int main() {
	cin >> n;

	go(1, n);

	cout << maxVal;

	return 0;
}