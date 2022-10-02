// 스도쿠 검증
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

int map[10][10], ret, flag;

void func(int y, int x) { // 블럭 검사 함수 
	int used3[10] = { 0 };
	for (int i = 0; i < 10; i++) used3[i] = 0;

	for (int i = y; i < y + 3; i++) {
		for (int j = x; j < x + 3; j++) {
			if (used3[map[i][j]] == 1) {
				flag = 1;
				break;
			}
			used3[map[i][j]] = 1;
		}
		if (flag == 1) break;
	}
}

int main() {
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) { // test case
		flag = 0;
		ret = 0;

		for (int i = 0; i < 9; i++) { // map 초기화 
			for (int j = 0; j < 9; j++) {
				cin >> map[i][j];
			}
		}

		int used1[10] = { 0 }, used2[10] = { 0 };

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) { // 가로 검사
				if (used1[map[i][j]] == 1) {
					flag = 1;
					break;
				}
				used1[map[i][j]] = 1;
			}if (flag == 1) break;

			for (int j = 0; j < 9; j++) { // 세로 검사
				if (used2[map[j][i]] == 1) {
					flag = 1;
					break;
				}
				used2[map[j][i]] = 1;
			}if (flag == 1) break;

			for (int c = 0; c < 10; c++) { // used1, 2 초기화
				used1[c] = 0;
				used2[c] = 0;
			}
		}

		if (flag != 1) {
			for (int i = 0; i < 9; i += 3) { // 블록 검사
				for (int j = 0; j < 9; j += 3) {
					func(i, j);
				}
			}
		}

		if (flag == 1) ret = 0;
		else ret = 1;

		cout << "#" << tc + 1 << " " << ret << endl;
	}

	return 0;
}