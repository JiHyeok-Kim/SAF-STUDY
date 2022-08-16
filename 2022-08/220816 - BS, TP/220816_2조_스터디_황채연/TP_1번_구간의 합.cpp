#include <iostream>
using namespace std;

int N, M;
int arr[10000];
int ret;

void slidingWindow(int sp) {
	int sum = 0;
	for (int i = sp; i < N; ++i) {
		sum += arr[i];
		if (sum == M) {
			ret++;
			break;
		}

		if (sum > M) break;
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; ++i) {
		slidingWindow(i);
	}

	cout << ret;
	return 0;
}