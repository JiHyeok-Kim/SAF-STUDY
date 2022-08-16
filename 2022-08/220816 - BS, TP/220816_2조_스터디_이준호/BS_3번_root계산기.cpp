#include <iostream>
#include <string>
using namespace std;

int n;

int bs(int s, int e) {
	int last;
	while (s <= e) {
		long long mid = (s + e) / 2;

		if (mid * mid == n) return mid;
		if (mid * mid > n) {
			e = mid - 1;
		}
		else {
			last = mid;
			s = mid + 1;
		}
	}
	return last;
}

int main() {
	cin >> n;

	int ret = bs(0, n);
	cout << ret;

	return 0;
}