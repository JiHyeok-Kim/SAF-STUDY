#include <iostream>
using namespace std;

int N, M;
int arr[100001];
int sum[100001];

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}
	
	sum[0] = 0;
	sum[1] = arr[1];
	for (int i = 2; i <= N; ++i) {
		sum[i] = sum[i - 1] + arr[i];
	}

	for (int i = 0; i < M; ++i) {
		int num1, num2;
		cin >> num1 >> num2;
		cout << sum[num2] - sum[num1 - 1] << "\n";
	}
	return 0;
}