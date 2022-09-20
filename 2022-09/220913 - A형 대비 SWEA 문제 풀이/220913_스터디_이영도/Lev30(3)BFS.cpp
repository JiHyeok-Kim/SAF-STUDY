// 트리 인접행렬 BFS
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
	{0, 1, 0, 0, 1, 0},
	{0, 0, 1, 0, 0, 1},
	{0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0}
};
queue<int> que;
int K;

void bfs() {

	while (!que.empty()) {
		int tmp;
		tmp = que.front();
		que.pop();
		
		cout << tmp << " ";
	}
}

int main() {
	cin >> K;

	que.push(K);
	for (int i = K; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (map[i][j] == 1) {
				que.push(j);
			}
		}
	}

	bfs();
	
	return 0;
}