#include <iostream>
using namespace std;

int n, m;
int q;

int arr[100001];
int acc[100001];

int getSum(int a, int b) {
	if (a == b) return arr[a];
	return acc[b] - acc[a - 1];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int idx, people;
		cin >> idx >> people;
		arr[idx] = people;
	}
	cin >> q;

	acc[0] = arr[0];

	for (int i = 1; i <= m; i++) {
		acc[i] = acc[i - 1] + arr[i];
	}

	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		cout << getSum(a, b) << '\n';
	}

	return 0;
}