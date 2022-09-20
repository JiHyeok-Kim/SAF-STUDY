// �׷��� BFS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <algorithm>

using namespace std;

int map[6][6] = {
	{0, 0, 0, 0, 1, 0},
	{1, 0, 1, 0, 0, 1},
	{1, 0, 0, 1, 0, 0},
	{1, 1, 0, 0, 0, 0},
	{0, 1, 0, 1, 0, 1},
	{0, 0, 1, 1, 0, 0}
};
int used[7];
queue<int> que;

void bfs(int K) {

	que.push(K); // ���� ��
	used[K] = 1;

//	for (int next = 0; next < 6; next++) { // ���� �� ���� �ʱ�ȭ
//		if (map[K][next] == 1) que.push(next);
//	}

	while (!que.empty()) {
		int now = que.front(); 
		que.pop(); 
		
		cout << now << endl; // ���

		for (int next = 0; next < 6; next++) { // ���� ���� �ʱ�ȭ
			if (used[next] == 1) continue; // ��� üũ
			if (map[now][next] == 1) {
				que.push(next); // que�� �� �ֱ�
				used[next] = 1; // �����
			}
		}
	}
}

int main() {
	int K;
	cin >> K;

	bfs(K);

	return 0;
}