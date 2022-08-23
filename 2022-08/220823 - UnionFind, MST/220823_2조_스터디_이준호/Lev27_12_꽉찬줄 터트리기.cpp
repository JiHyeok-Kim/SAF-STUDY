#include <iostream>
#include <string>
using namespace std;

int arr[5][4];

void eli(int y) {
	for (int k = 0; k < 4; k++) {
		arr[y][k] = 0;
	}
}

void down(int y) {
	for (int i = y; i >= 1; i--) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = arr[i - 1][j];
		}
	}
	for (int x = 0; x < 4; x++) {
		arr[0][x] = 0;
	}

}


int main() {
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 4;x++) {
			cin >> arr[y][x];
		}
	}

	for (int y = 0; y < 5; y++) {
		int cnt = 0;
		for (int x = 0; x < 4;x++) {
			if (arr[y][x] == 1) cnt++;
		}

		if (cnt == 4) {
			eli(y);
			down(y);

		}
	}

	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 4;x++) {
			cout << arr[y][x] << " ";
		}
		cout << "\n";
	}

	return 0;
}