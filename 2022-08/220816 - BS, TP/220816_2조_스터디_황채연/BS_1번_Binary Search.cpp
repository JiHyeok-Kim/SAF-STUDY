#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int arr[100000];
int target;

void bs(int sp, int ep) {
	while (sp <= ep) {
		int mid = (sp + ep) / 2;
		if (arr[mid] == target) {
			cout << "O";
			return;
		}

		if (arr[mid] < target) sp = mid + 1;
		if (arr[mid] > target) ep = mid - 1;
	}

	cout << "X";
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> target;
		bs(0, n - 1);
	}
	return 0;
}