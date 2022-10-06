#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int T;
int in[7];
bool visited[7];
int DAT[301];
vector<int> v;

void DFS(int cnt, int sp, int sum) {
	if (cnt == 3) {
		v.push_back(sum);
		return;
	}

	for (int i = sp; i >= 0; --i) {
		if (visited[i] == true) continue;
		visited[i] = true;
		DFS(cnt + 1, i, sum + in[i]);
		visited[i] = false;
	}
}

int Solve() {
	sort(in, in + 7);
	DFS(0, 6, 0);
	sort(v.begin(), v.end());
	int cnt = 0;
	for (int i = v.size() - 1; i >= 0; --i) {
		if (DAT[v[i]] == 1) continue;
		if (cnt == 4) return v[i];
		DAT[v[i]] = 1;
		cnt++;
	}
}

void init() {
	memset(DAT, 0, sizeof(DAT));
	v.clear();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		init();
		for (int i = 0; i < 7; ++i) {
			cin >> in[i];
		}

		int ret = Solve();
		cout << "#" << tc << " " << ret << "\n";
	}
	return 0;
}