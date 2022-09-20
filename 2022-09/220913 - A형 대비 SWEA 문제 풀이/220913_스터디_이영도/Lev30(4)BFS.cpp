// 그래프 BFS
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

	que.push(K); // 시작 값
	used[K] = 1;

//	for (int next = 0; next < 6; next++) { // 시작 값 라인 초기화
//		if (map[K][next] == 1) que.push(next);
//	}

	while (!que.empty()) {
		int now = que.front(); 
		que.pop(); 
		
		cout << now << endl; // 출력

		for (int next = 0; next < 6; next++) { // 다음 라인 초기화
			if (used[next] == 1) continue; // 사용 체크
			if (map[now][next] == 1) {
				que.push(next); // que에 값 넣기
				used[next] = 1; // 사용함
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