#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int Arr[3][4] = {
	{3,2,5,3},
	{7,6,1,6},
	{4,9,2,7}
};
int A;
int main() {
	//FILE* freinput = freopen("input.txt", "rt", stdin);
	int cnt;
	for (int j = 0; j < 4; j++) {
		cin >> A;
		cnt = 0;
		while (1) {
			if (cnt == A) break;
			
			for (int i = 2; i >=1; i--) {
				int temp = Arr[i][j];
				Arr[i][j] = Arr[i - 1][j];
				Arr[i - 1][j] = temp;
			}
			cnt++;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << Arr[i][j];
		}cout << '\n';
	}
	return 0;
}