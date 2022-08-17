#include <iostream>
using namespace std;

int arr[1100][1100];
int n, m;
int yy1, xx1, yy2, xx2;
int sumarr[1100][1100];


int main() {
	cin >> n >> m;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			cin >> arr[y][x];
		}
	}

	int ditY[4] = { -1,0,-1,0 };
	int ditX[4] = { 0,-1,-1,0 };


	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			for (int i = 0; i < 4; i++) {
				int ny = y + ditY[i];
				int nx = x + ditX[i];
				if (i == 2) {
					sumarr[y][x] -= sumarr[ny][nx];
				}
				if (i == 3) {
					sumarr[y][x] += arr[ny][nx];
				}
				if (i == 0 || i == 1) {
					sumarr[y][x] += sumarr[ny][nx];
				}

			}

		}
	}

	for (int i = 0; i < m; i++) {
		cin >> yy1 >> xx1 >> yy2 >> xx2;
		int res = sumarr[yy2][xx2] - (sumarr[yy1 - 1][xx2] + sumarr[yy2][xx1 - 1]) + sumarr[yy1 - 1][xx1 - 1];
		cout << res << "\n";
	}


	return 0;
}