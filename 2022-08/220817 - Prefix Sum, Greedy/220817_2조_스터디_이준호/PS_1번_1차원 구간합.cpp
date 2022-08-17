#include <iostream>
using namespace std;

int n, m;
int arr[100001];
int a, b;
int sum = 0;
int sums[100001];

void hap(int a, int b) {
	if (a == 1) cout << sums[b - 1] << endl;
	else {
		cout << sums[b - 1] - sums[a - 2] << endl;
	}

}


int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		sums[i] = sum;
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		hap(a, b);
	}

	return 0;
}