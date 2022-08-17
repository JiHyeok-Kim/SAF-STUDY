#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int fix[1001];

int main() {
	int n, l;
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (fix[i] == 1) continue;
		fix[i] = 1;
		cnt++;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] - arr[i] + 1 > l) break;
			fix[j] = 1;
		}
	}

	cout << cnt;

	return 0;
}