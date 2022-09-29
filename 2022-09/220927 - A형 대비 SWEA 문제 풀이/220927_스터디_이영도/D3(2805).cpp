// 농작물 수확하기
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
int map[50][50];
string smap[50];

int main() {
	int TC;
	cin >> TC;

	for (int t = 0; t < TC; t++) {
		int n, sum = 0;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> smap[i];
		}

		for (int i = 0; i < n; i++) { // map 초기화
			for (int j = 0; j < n; j++) {
				map[i][j] = smap[i][j] - '0';
			}
		}

		int start = n / 2;

		for (int i = 1; i <= start; i++) { // 더하기 연산
			for (int j = 0; j < i; j++) { // 상단
				sum += map[i-1][start + j]; 
				sum += map[i-1][start - j];
			}
			for (int j = (start + 1) - i; j >= 0; j--) {
				sum += map[start + (i - 1)][start + j];
				sum += map[start + (i - 1)][start - j]; 
			}
		}

		sum += map[n - 1][start];
		sum += map[n - 1][start];

		for (int i = 0; i < n; i++) { // 중복 제거
			sum -= map[i][start]; // 세로 중복 제거
			// sum -= map[start][i]; // 가로 중복 제거
		} // sum -= map[start][start]; // 가운데 중복 제거

		cout << "#" << t + 1 << " " << sum << endl;
	}

	return 0;
}