#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int Arr[4][5];

void block() {
	for (int i = 3; i >= 0; i--) {
		for (int j = 4; j >= 0; j--) {
			if (Arr[i][j] == 1) {
				cout << "(" << i << "," << j << ")" << '\n';
				return;
			}
		}
	}
	return;
}

int main() {
	//FILE* freinput = freopen("input.txt", "rt", stdin);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> Arr[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			if (Arr[i][j] == 1) {
				cout << "(" << i << "," << j << ")" << '\n';
				block();
				return 0;
			}
		}
	}
	return 0;
}