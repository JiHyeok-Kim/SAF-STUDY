#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

long long n, m;
long long arr[100001];
long long minTime = 21e8;

void bs() {
	long long s = 1;
	long long e = 10e8;

	while (s <= e) {
		long long mid = (s + e) / 2;

		long long temp = 0;
		for (int i = 0; i < n; i++) {
			temp += mid / arr[i];
		}

		if (temp >= m) {
			if (minTime > mid) minTime = mid;
			e = mid - 1;
		}
		else s = mid + 1;
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		long long t;
		cin >> t;
		arr[i] = t;
	}

	bs();
	cout << minTime;

	return 0;
}