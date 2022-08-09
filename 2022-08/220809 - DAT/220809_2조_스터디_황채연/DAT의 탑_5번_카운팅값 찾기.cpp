#include <iostream>
using namespace std;

int main()
{
	int arr[3][5] = {
	{1, 3, 3, 5, 1},
	{3, 6, 2, 4, 2},
	{1, 9, 2, 6, 5}
	};
	int cnt[10] = { 0, };
	int N;
	cin >> N;

	for (int y = 0; y < 3; ++y) {
		for (int x = 0; x < 5; ++x) {
			cnt[arr[y][x]]++;
		}
	}

	for (int i = 1; i <= 9; ++i) {
		if (cnt[i] == N) cout << i << " ";
	}
	return 0;
}