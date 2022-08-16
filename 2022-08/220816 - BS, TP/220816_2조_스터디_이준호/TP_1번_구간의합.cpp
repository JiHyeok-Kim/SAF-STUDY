#include <iostream>
using namespace std;

int n, m;
int arr[10001];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int cnt = 0;
	for (int k = 0; k < n; k++) {
		int sum = 0;
		for (int x = k; x < n; x++) {
			sum += arr[x];
			if (sum == m) { cnt++; break; }
			else if (sum > m) break;
		}
	}
	cout << cnt;
}