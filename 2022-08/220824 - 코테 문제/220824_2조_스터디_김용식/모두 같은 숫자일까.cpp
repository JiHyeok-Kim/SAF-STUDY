#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int Arr[3][3];
int cnt = 0;

int main() {
	//FILE* freinput = freopen("input.txt", "rt", stdin);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> Arr[i][j];
		}
	}
	int cnt;
	
	for (int i = 0; i < 3; i++) {
		cnt = 0;
		for (int j = 1; j < 3; j++) {
			if (Arr[i][j] != Arr[i][j - 1]) {
				cout << 'x' << '\n';
				break;
			}
			else {
				cnt++;
				if (cnt == 2) {
					cout << Arr[i][j] << '\n';
				}
			}
		}
	}
	return 0;
}