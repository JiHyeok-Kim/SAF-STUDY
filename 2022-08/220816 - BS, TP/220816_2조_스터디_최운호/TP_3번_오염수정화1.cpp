#include <iostream>
#include <algorithm>
using namespace std;

int n;
int idx;

int arr[100000];
int result = 21e8;
int w1, w2;

void check(int a, int b) {
	int mini = 21e8;

	while (a < b) {
		int gap = abs(arr[a] + arr[b]);
		if (mini > gap) {
			mini = gap;
			w1 = a;
			w2 = b;
		}

		if (arr[a] + arr[b] == 0) return;

		if (arr[a] + arr[b] > 0) b--;
		else if (arr[a] + arr[b] < 0) a++;
	}

	return;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	check(0, n - 1);

	cout << arr[w1] << " " << arr[w2];

	return 0;
}