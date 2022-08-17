#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>

using namespace std;

int main() {
	int N, L, arr[1001], cnt = 0;
	cin >> N >> L;

	for (int i = 0; i < N; i++) { cin >> arr[i]; }
	sort(arr, arr + N);

	int s = arr[0];

	for (int i = 1; i < N; i++) {
		if (arr[i] - s >= L) {
			cnt++;
			s = arr[i];
		}
	}cout << ++cnt << endl;

	return 0;
}