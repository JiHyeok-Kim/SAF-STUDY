#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>

using namespace std;
int arr[100001], acc[100001];

void run(int a, int b) {
	cout << (acc[b] - acc[a - 1]) << endl;
}

int main() {
	int N, Q, a[100001], b[100001];
	cin >> N >> Q;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		acc[i] = acc[i - 1] + arr[i];
	}
	for (int i = 0; i < Q; i++) { cin >> a[i] >> b[i]; }
	for (int i = 0; i < Q; i++) { run(a[i], b[i]); }

	return 0;
}