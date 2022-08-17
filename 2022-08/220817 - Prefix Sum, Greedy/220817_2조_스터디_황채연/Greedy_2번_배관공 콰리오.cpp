#include <iostream>
#include <algorithm>
using namespace std;

int N, L;
int arr[1000];

int main()
{
	cin >> N >> L;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	int tape_len = -1;
	int tape_num = 0;
	int tape_over = 0;
	int sp = 0;

	while (1) {
		tape_len = L;
		for (int i = sp; i < N; ++i) {
			if (i + 1 >= N) {
				tape_over = 1;
				break;
			}
			int dist = arr[i + 1] - arr[sp] + 1;
			if (dist <= tape_len) continue;
			tape_num++;
			sp = i + 1;
		}

		if (tape_over == 1) {
			tape_num++;
			break;
		}
	}

	cout << tape_num;
	return 0;
}