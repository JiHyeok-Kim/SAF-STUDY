#include <iostream>
#include <queue>
int Arr[11][11] = { 0 };
using namespace std;
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Arr[i][j];
		}
	}
	int used[10] = { 0 };
	used[0] = 1;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		cout << now << " ";

		for (int next = 0; next <= 10 ;next++) {
			if (Arr[now][next] == 0)continue;
			if (used[next] == 1)continue;
			used[next] = 1;
			q.push(next);
		}
		
	}

	return 0;
}