#include <iostream>
#include <string>
using namespace std;
int T, N;
int nasa[22][2];
string r;

void dfs(int l,string p,int* u ) {
	if (p.length() > r.length()) r = p;
	if (l == N) return;

	for (int i = 0; i < N; i++) {
		if (u[i] == 1)continue;
		if (l != 0 && nasa[int(p[p.length() - 1])][1] != nasa[i][0])continue;
		u[i] = 1;
		dfs(l + 1, p + char(i), u);
		u[i] = 0;
	}
}
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		r = "";
		cin >> N; int u[22] = { 0 }; int* pu; pu = u;
		for (int i = 0; i < N; i++)cin >> nasa[i][0] >> nasa[i][1];
		dfs(0, "", pu);
		cout << "#" << t << " ";
		for (int i = 0; i < r.length(); i++) {
			cout << nasa[int(r[i])][0] << " " << nasa[int(r[i])][1] << " ";
		}
		cout << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}