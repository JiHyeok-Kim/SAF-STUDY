#include <iostream>
using namespace std;

int Arr[9][9] = { 0 };
int used[10] = { 0 };

void clear() {
	for (int i = 0; i < 10; i++) {
		used[i] = 0;
	}
	return;
}

int FindG() {
	
	int A = 0;
	while (A<9) {
		for (int i = 0; i < 9; i++) {
			if (used[Arr[A][i]] == 1)return 1;
			used[Arr[A][i]] = 1;
		}
		A++;
		clear();
	}
	clear();
	return 0;
}

int FindS() {
	int A = 0;
	while (A < 9) {
		for (int i = 0; i < 9; i++) {
			if (used[Arr[i][A]] == 1)return 1;
			used[Arr[i][A]] = 1;
		}
		A++;
		clear();
	}
	clear();
	return 0;
}

int FindN() {
	int A = 0;
	int B = 0;
	int cnt = 0;
	while (1) {
		if (cnt == 3)break;

		for (int i = A + 0; i < A + 3; i++) {
			for (int j = B + 0; j < B + 3; j++) {
				if (used[Arr[i][j]] == 1)return 1;
				used[Arr[i][j]] = 1;
			}
		}
		A += 3;
		clear();
		if (A == 9) {
			A = 0;
			B += 3;
			cnt++;
		}
	}



	return 0;
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int Tc;
	cin >> Tc;


	for (int k = 1; k <= Tc; k++) {
		clear();
		// 입력받기
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> Arr[i][j];
			}
		}

		//가로확인
		int Garo = FindG();
		//세로확인
		int Sero = FindS();
		//네모확인
		int Nemo = FindN();

		if (Garo == 1 || Sero == 1 || Nemo == 1) {
			cout << "#" << k << " " << "0" << '\n';
		}
		else {
			cout << "#" << k << " " << "1" << '\n';
		}
	}



	return 0;
}