// 코딩 던전
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct str{
	int link;
	int gold;
};

vector<str> v[11];
vector<int> result;
int N, M, K;

void bfs() {
	queue<str> q;
	
	for (int i = 0; i < v[0].size(); i++) {
		int tmp = v[0][i].gold;
		if (tmp > K) continue;
		q.push({ v[0][i].link, tmp });
		result.push_back(v[0][i].link);
	}

	while (!q.empty()) {
		// BFS 
		// 다음 갈 곳 돈 초기화 for 
		// now 골드 + ㅎ다음 골드 > K continue
		// 저장
		str now = q.front();
		q.pop();
		
		int pay = now.gold;

		for (int i = 0; i < v[now.link].size(); i++) {
			int tmp = v[now.link][i].gold;
			if (tmp + pay > K) continue; 
			q.push({ v[now.link][i].link, (pay + tmp)});
			result.push_back(v[now.link][i].link);
		}
	}
}

int main() {
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}

	bfs();

	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	} cout << endl;

	return 0;
}