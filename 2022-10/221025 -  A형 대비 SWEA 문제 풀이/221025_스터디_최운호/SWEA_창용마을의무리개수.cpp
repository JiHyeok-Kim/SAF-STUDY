#include <iostream>
#include <vector>
using namespace std;

int vill[101];
int answer;
int N, M;
vector<int> group[101];

int Find(int now) {
	if (vill[now] == now) return now;

	int ret = Find(vill[now]);
	vill[now] = ret;

	return ret;
}

void Union(int a, int b) {
	int p1 = Find(a);
	int p2 = Find(b);

	if (p1 == p2) return;
	vill[p2] = p1;
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> N >> M;
		answer = 0;

		for (int i = 1; i <= N; i++) {
			vill[i] = i;
		}

		for (int i = 0; i < M; i++) {
			int A, B;
			cin >> A >> B;
			Union(A, B);
		}

		bool dat[100] = { 0 };

		for (int i = 1; i <= N; i++) {
			int tmp = Find(i);
			group[tmp].push_back(i);
		}

		for (int i = 1; i <= N; i++) {
			if (group[i].size() == 0) continue;
			answer++;
			group[i].clear();
		}

		cout << "#" << t << " " << answer << '\n';
	}
	return 0;
}