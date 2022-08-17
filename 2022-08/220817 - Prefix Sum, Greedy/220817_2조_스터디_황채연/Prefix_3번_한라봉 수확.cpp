#include <iostream>
using namespace std;

int N;
int arr[100001];
int sum[100001];

void makeAccSum(int point) {
	sum[point] = arr[point];
	for (int i = point - 1; i >= 0; --i) {
		if (i < 0) break;
		sum[i] = sum[i + 1] + arr[i];
	}

	for (int i = point + 1; i < N; ++i) {
		if (i >= N) break;
		sum[i] = sum[i - 1] + arr[i];
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	int ret_max = -1;
	for (int i = 0; i < N; ++i) {
		int point = i;
		if (point >= 1 && point <= N - 2) continue;
		makeAccSum(point);
		
		// max가 나올 수 있는 경우
		if (point == 0) {
			int offset = sum[N - 1] - sum[0];
			for (int j = 1; j <= N - 1; ++j) {
				int target = (offset - arr[j]) + (sum[N - 1] - sum[j]);
				if (ret_max < target) {
					ret_max = target;
				}
			}
		}
		if (point == N - 1) {
			int offset = sum[0] - sum[N - 1];
			for (int j = N - 2; j >= 0; --j) {
				int target = (offset - arr[j]) + (sum[0] - sum[j]);
				if (ret_max < target) {
					ret_max = target;
				}
			}

		}
	}

	cout << ret_max;
	return 0;
}