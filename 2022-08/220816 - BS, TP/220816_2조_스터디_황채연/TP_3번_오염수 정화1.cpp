#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[100000];
int ret = 0x7fffffff;
int ret_left, ret_right;

void twoPointer(int sp, int ep) {
	while (sp < ep) {
		int sum = arr[sp] + arr[ep];
		int dist = abs(sum);
		
		if (ret == dist) {
			if (abs(ret_left) < abs(arr[sp])) ret_left = arr[sp];
			if (abs(ret_right) < abs(arr[ep])) ret_right = arr[ep];
		}
		if (ret > dist) {
			ret = dist;
			ret_left = arr[sp];
			ret_right = arr[ep];
			if (ret == 0) return;
		}

		if (abs(arr[sp]) < abs(arr[ep])) ep--;
		else sp++;
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	twoPointer(0, N - 1);
	cout << ret_left << " " << ret_right;
	return 0;
}