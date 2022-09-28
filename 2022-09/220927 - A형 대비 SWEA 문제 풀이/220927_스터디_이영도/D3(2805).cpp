// ���۹� ��Ȯ�ϱ�
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

		for (int i = 0; i < n; i++) { // map �ʱ�ȭ
			for (int j = 0; j < n; j++) {
				map[i][j] = smap[i][j] - '0';
			}
		}

		int start = n / 2;

		for (int i = 1; i <= start; i++) { // ���ϱ� ����
			for (int j = 0; j < i; j++) { // ���
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

		for (int i = 0; i < n; i++) { // �ߺ� ����
			sum -= map[i][start]; // ���� �ߺ� ����
			// sum -= map[start][i]; // ���� �ߺ� ����
		} // sum -= map[start][start]; // ��� �ߺ� ����

		cout << "#" << t + 1 << " " << sum << endl;
	}

	return 0;
}