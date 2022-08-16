#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100001];

int Fidx = 0;
int Lidx = 1;
int a, b;

void cleaning() {
	int sum = 0;
	
	int mini = 21e7;
	while (Fidx < (n-Lidx)) {
		sum = arr[Fidx] + arr[n - Lidx];
		
		if (abs(sum) < mini) {
			mini = abs(sum);
			a = Fidx;
			b = Lidx;
		}

		if (sum == 0) return;

		
		if (sum < 0) {
			Fidx++;
			sum = 0;
		}
		if (sum > 0) {
			Lidx++;
			sum = 0;
		}
		
	}
	
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	if (arr[0] <= 0 && arr[n - 1] < 0) {
		cout << arr[n - 2] << " " << arr[n - 1];
	}
	else if (arr[0] >= 0 && arr[n - 1] > 0) {
		cout << arr[0] << " " << arr[1];
	}
	else {
		cleaning();
		cout << arr[a] << " " << arr[n - b];
	}


	return 0;
}