#include <iostream>
using namespace std;
long long N, result[1010], fac[1010], fac1[1010];
#define M 1000000007;
void solve() {
	int T;
	cin >> T; fac[0] = 1;
	for (int i = 1; i <= 1000; i++) {
		fac[i] = (fac[i - 1] * i) % M;
		result[i] = (result[i - 1] * i + ((i / 2) * fac[i - 1])) % M;
	}
	for (int t = 1; t <= T; t++) {
		cin >> N;
		cout << "#" << t << " " << result[N] << "\n";
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