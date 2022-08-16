#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int arr[10001];
int N, M;

/*
int getSum() {
	int sum = 0;
	for (int i = 0; i < M; i++) sum += arr[i];
	return sum;
}
*/

int main() {
	int cnt = 0, sum = 0, str = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	} // int sum = getSum();


	sum = arr[0];
	int i = 1;
	while (i <= N) {
		// if (i == N - M) break;
		if (sum == M) {
			cnt++;
			sum -= arr[str];
			str++;
		}

		else if (sum < M) {
			sum += arr[i];
			i++;
		}
		else if (sum > M) {
			sum -= arr[str];
			str++;
		}
	}

	cout << cnt << endl;

	return 0;
}