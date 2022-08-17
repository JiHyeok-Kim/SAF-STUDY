#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>

using namespace std;

int arr[100001], acc[100001];

int main() {
	int N, M, tmp = 0, Q, x1, x2;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		cin >> arr[tmp];
	}

	for (int i = 1; i <= M; i++) {
		acc[i] = acc[i - 1] + arr[i];
	}

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> x1 >> x2;
		cout << acc[x2] - acc[x1 - 1] << endl;
	}

	return 0;
}