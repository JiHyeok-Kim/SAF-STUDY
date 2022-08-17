#include <iostream>
using namespace std;

int n, m;

int arr[100001];
int line[100001];
int getSum(int a, int b) {
	if (a > b) return 0;
	if (a == b) return arr[a];

	return line[b] - line[a - 1];
}
int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	line[1] = arr[1];

	for (int i = 2; i <= n; i++) {
		line[i] = line[i - 1] + arr[i];
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		int result = getSum(a, b);
		cout << result << '\n';
	}

	return 0;
}