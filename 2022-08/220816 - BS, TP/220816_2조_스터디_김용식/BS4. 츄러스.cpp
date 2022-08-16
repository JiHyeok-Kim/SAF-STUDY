#include <iostream>
using namespace std;
int n, k;
int chu[10001];

int iscount(int c) {
	int cnt = 0;
	for (int i = 0; i < 10001; i++) {
		cnt += chu[i] / c ;
	}
	return cnt;
}


int bs(int s, int e) {
	int last;
	while (s<=e) {
		
		int mid = (s + e) / 2;
		int cnt = iscount(mid);
		if (cnt >= k) {
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
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> chu[i];
	}	
	int ret = bs(1, 21e7);
	cout << ret;

	return 0;
}