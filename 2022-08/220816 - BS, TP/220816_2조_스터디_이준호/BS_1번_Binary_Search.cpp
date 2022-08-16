#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];
int input[1000];
int n, k;

int bs(int s, int e, int tar) {

	while (s <= e) {
		int mid = (s + e) / 2;

		if (arr[mid] == tar) {
			return 1;
		}
		if (arr[mid] < tar) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> input[i];
		int ret = bs(0, n, input[i]);
		if (ret == 1) cout << "O";
		else cout << "X";
	}

	return 0;
}