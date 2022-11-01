#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N, M, result;
string a[110000];
string b[110000];

void input() {
	result = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)cin >> a[i];
	for (int i = 0; i < M; i++)cin >> b[i];
}
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		sort(a, a + N);
		sort(b, b + M);
		int ap = 0, bp = 0;
		while (ap < N && bp < M) {
			if (a[ap] == b[bp]) {
				result++; ap++; bp++;
			}
			if (a[ap] > b[bp]) bp++;
			if (a[ap] < b[bp]) ap++;
		}
		cout << "#" << t << " " << result << "\n";
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