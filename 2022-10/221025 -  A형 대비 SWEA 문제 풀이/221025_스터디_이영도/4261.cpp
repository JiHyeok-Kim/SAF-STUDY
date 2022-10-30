// ���� �޴���ȭ Ű�е�
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

// ���� ����
string map = "22233344455566677778889999";
string key, dict[1001];
int N, cnt = 0;

int isValid(int now) { // Valid check func
	int tmp_cnt = 0;
	string tmp = dict[now];

	// length check
	if (tmp.length() != key.length()) return 0;

	for (int i = 0; i < key.length(); i++) {
		int idx = tmp[i] - 'a';
		if (map[idx] == key[i]) {
			tmp_cnt++;
		}
	}

	if (tmp.length() != tmp_cnt) { // ���� ����
		return 0;
	}

	return 1; // ��ȿ�� ���� ����
}

void init() { // initialization func
	N = 0;
	cnt = 0;
}

int main() {
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		init(); // init func call
		cin >> key >> N;

		for (int i = 0; i < N; i++) { // input
			cin >> dict[i];
		}

		for (int i = 0; i < N; i++) {
			// isValid func call
			cnt += isValid(i);
		}

		cout << "#" << tc + 1 << " " << cnt << endl;
	}

	return 0;
}