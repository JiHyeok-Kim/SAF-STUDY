#include <iostream>
using namespace std;
int cntNode, cntEdge;
int Arr[101][101] = { 0 };
int used[101] = { 0 };
int used2[101] = { 0 };

void dfs(int now) {
	cout << now << " ";
	for (int next =cntNode; next >= 1; next--) {
		if (Arr[now][next] == 0)continue;
		if (used[next] == 1)continue;
		used[next] = 1;
		dfs(next);
	}
	return;
}

void dfs2(int now) {
	for (int next = cntNode; next >0; next--) {
		if (Arr[now][next] == 0)continue;
		if (used2[next] == 1)continue;
		used2[next] = 1;
		dfs2(next);
	}
	cout << now << " ";
}


int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> cntNode >> cntEdge;
	int N;
	cin >> N;
	for (int i = 0; i < cntEdge; i++) {
		int from, to;
		cin >> from >> to;
		Arr[from][to] = 1;
	}
	used[N] = 1;
	dfs(N);
	cout <<  '\n';
	used2[N] = 1;
	dfs2(N);

	return 0;
}