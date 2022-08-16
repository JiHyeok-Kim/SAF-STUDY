#include <iostream>
using namespace std;
int square;

int bs(int s, int e) {
	int last=0;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (mid == square/mid) {
			return mid;
		}
		if (mid < square/mid) {
			last = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	return last;
}

int main() {
	cin >> square;
	int ret = bs(1, square);
	cout << ret;
	return 0;
}