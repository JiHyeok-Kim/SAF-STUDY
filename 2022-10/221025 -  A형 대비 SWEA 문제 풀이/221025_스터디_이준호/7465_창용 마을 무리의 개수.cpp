#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n, m, ans;
int parents[110];
struct Node {
	int a, b;
};
vector<Node> tong;
unordered_map<int, int> ansTong;

void init() {
	ans = 0;
	tong.clear();
	ansTong.clear();
}

void input() {
	cin >> n >> m;
	int temp1, temp2;
	for (int i = 0; i < m; i++) {
		cin >> temp1 >> temp2;
		tong.push_back({ temp1, temp2 });
	}
}


int Find(int now) {
	if (parents[now] == now) return now;

	int ret = Find(parents[now]);
	parents[now] = ret;

	return ret;
}

void Union(int aa, int bb) {
	int t1 = Find(aa);
	int t2 = Find(bb);
	if (t1 == t2) return;
	parents[t2] = t1;
}

void solve() {
	for (int i = 0; i < 110; i++) {
		parents[i] = i;
	}
	for (int i = 0; i < m; i++) {
		Union(tong[i].a, tong[i].b);
	}

	for (int i = 1; i <= n; i++) {
		ansTong[Find(i)]++;
	}
	ans = ansTong.size();
}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		init();
		input();
		solve();
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}