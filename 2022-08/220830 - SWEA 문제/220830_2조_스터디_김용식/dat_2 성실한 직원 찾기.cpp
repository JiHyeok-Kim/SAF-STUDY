#include <iostream>
using namespace std;
int Arr[1001][1001] = { 0 };
long long dat[10000001] = { 0 };
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int H, W;
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> Arr[i][j];
			dat[Arr[i][j]]++;
		}
	}
	int max = -2134567890;
	int maxIdx = 0;
	for (int i = 0; i < 10000001; i++) {
		if (dat[i] > max) {
			max = dat[i];
			maxIdx = i;
		}
	}
	cout << maxIdx;
	return 0;
}