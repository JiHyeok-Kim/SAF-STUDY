#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int six[50];
int one[50];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> six[i] >> one[i];
	}

	sort(six, six + M);
	sort(one, one + M);
	if (one[0] * 6 <= six[0]) {
		cout << N * one[0];
		return 0;
	}

	int buy_six_num = N / 6;
	int rest = N % 6;
	if (rest * one[0] <= six[0]) {
		cout << rest * one[0] + buy_six_num * six[0];
	}
	else {
		cout << (buy_six_num + 1) * six[0];
	}

	return 0;
}