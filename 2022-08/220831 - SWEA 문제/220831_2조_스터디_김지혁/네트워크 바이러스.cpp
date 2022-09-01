#include <iostream>
using namespace std;
int Arr[101][101] = { 0 };
int used[101] = { 0 };
int cntNode, cntEdge;
int cnt=0;
void dfs(int now) {	
	for (int next = 0; next <= cntNode; next++) {
		if (Arr[now][next] == 0)continue;
		if (used[next] == 1) continue;
		used[next] = 1;
		cnt++;
		dfs(next);
	}


	return;
}


int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> cntNode >> cntEdge;
	for (int i = 0; i < cntEdge; i++) {
		int from, to;
		cin >> from >> to;
		Arr[from][to] = 1;
		Arr[to][from] = 1;
	}
	
	used[1] = 1;
	dfs(1);
	cout << cnt;




	return 0;
}