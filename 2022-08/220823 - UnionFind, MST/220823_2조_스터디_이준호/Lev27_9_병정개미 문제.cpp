#include <iostream>
using namespace std;

int main() {
	int arr[4][4];
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cin >> arr[y][x];
		}
	}
	int cnt = 0;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 3; x++) {
			if (arr[y][x] == 1 && arr[y][x + 1] == 1) {
				cnt++;
			}
		}
	}

	if (cnt >= 1) cout << "위험한 상태";
	else cout << "안전한 상태";
	return 0;
}