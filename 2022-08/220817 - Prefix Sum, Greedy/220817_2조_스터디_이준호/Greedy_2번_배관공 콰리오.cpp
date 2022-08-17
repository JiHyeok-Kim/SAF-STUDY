#include <iostream>
#include <algorithm>
using namespace std;

int arr[1100];
int arr2[1100];
int locat;
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> locat;
		arr[i] = locat;
	}
	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		arr2[arr[i]]++;
	}


	int ans = 0;
	int idx = 0;

	while (1) {
		if (idx >= 1100) break;
		if (arr2[idx] >= 1) {
			ans++;
			idx += m;
		}
		else {
			idx++;
		}

	}
	cout << ans;

	return 0;
}