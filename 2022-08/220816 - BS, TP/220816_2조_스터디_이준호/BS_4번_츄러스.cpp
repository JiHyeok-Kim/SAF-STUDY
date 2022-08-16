#include <iostream>
using namespace std;
int n, k;

int chu[11000];

int getCutCount(int tar) {
	//tar 으로 자르면 몇개 나와?
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += (chu[i] / tar);
	}
	return cnt;
}

int bs(int s, int e) {

	int last = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		int cc = getCutCount(mid);

		if (cc >= k) {
			last = mid;
			s = mid + 1;
		}
		else if (cc < k) {
			e = mid - 1;
		}
	}

	return last;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> chu[i];

	int ret = bs(1, 21e7);
	cout << ret;

}