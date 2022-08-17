#include <iostream>
using namespace std;

int N, M, Q;
int arr[100001];
int sum[100001];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		int idx, value;
		cin >> idx >> value;
		arr[idx] = value;
	}

	sum[1] = arr[1];
	for (int i = 2; i <= M; ++i) {
		sum[i] = sum[i - 1] + arr[i];
	}

	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int num1, num2;
		cin >> num1 >> num2;
		cout << sum[num2] - sum[num1 - 1] << "\n";
	}
	return 0;
}