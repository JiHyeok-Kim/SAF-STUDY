#include <iostream>
#include <vector>
using namespace std;

vector<int> Arr;

int main() {
	int N,M;
	cin >> N>>M;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		Arr.push_back(temp);
	}

	int plus = 0;
	int minus = 0;
	int sum = 0;
	int cnt = 0;

	while (plus <= Arr.size()) {
		if (sum < M) {
			sum += Arr[plus];
			plus++;
		}

		if (sum > M) {
			sum -= Arr[minus];
			minus++;
		}
		
		if (sum == M) {
			cnt++;
			sum += Arr[plus];
			plus++;
		}

	}
	cout << cnt;

	return 0;
}