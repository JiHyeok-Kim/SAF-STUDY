#include <iostream>
using namespace std;

int A[10000];

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int right = 0;
	int left = 0;
	int cnt = 0;
	int sum = 0;

	while (right <= N) {
		if (sum < M) {
			sum += A[right];
			right++;
		}
		if (sum > M) {
			sum -= A[left];
			left++;
		}
		if (sum == M) {
			cnt++;
			sum += A[right];
			right++;
		}
	}
	cout << cnt;

	return 0;
}