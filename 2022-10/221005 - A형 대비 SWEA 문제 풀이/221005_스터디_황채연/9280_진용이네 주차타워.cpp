#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, N, M;
int pcost[101];
int visited[101];
int wcar[2001];
vector<int> v;
queue<int> wait;

int Solve() {
	int sum = 0;
	for (int i = 0; i < v.size(); ++i) {
		int target = v[i];
		if (wait.size() > 0) {
			for (int j = 1; j <= N; ++j) {
				if (visited[j] > 0) continue;
				visited[j] = wait.front();
				wait.pop();
				break;
			}
		}
		if (target < 0) { // out
			for (int j = 1; j <= N; ++j) {
				if (visited[j] == -target) {
					sum += (wcar[-target] * pcost[j]);
					visited[j] = 0;
					break;
				}
			}
		}
		if (target > 0) { // in
			int flag = 0;
			for (int j = 1; j <= N; ++j) {
				if (visited[j] > 0) continue;
				visited[j] = target;
				flag = 1;
				break;
			}

			if (flag == 0) {
				wait.push(target);
			}
		}
	}

	return sum;
}

void init() {
	v.clear();
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> M;
		init();
		for (int i = 1; i <= N; ++i) {
			cin >> pcost[i];
		}
		for (int i = 1; i <= M; ++i) {
			cin >> wcar[i];
		}
		for (int i = 0; i < 2 * M; ++i) {
			int inout;
			cin >> inout;
			v.push_back(inout);
		}

		int ret = Solve();
		cout << "#" << tc << " " << ret << "\n";
	}
	return 0;
}