#include <iostream>
#include <string>
using namespace std;
int D, A, B, prime[1000010];
void mkprime() {
	prime[1] = 1;
	for (int num = 2; num <= 1000000; num++) {
		if (prime[num] == 1)continue;
		for (int j = num + num; j <= 1000000; j += num) prime[j] = 1;
	}
}
void input() {
	cin >> D >> A >> B;
}
void solve() {
	mkprime();
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		int result = 0;
		for (int i = A; i <= B; i++) {
			if (prime[i] == 1)continue;
			string num = to_string(i);
			int ret = num.find(D + '0');
			if (ret == -1) continue;
			else {
				if (prime[i] == 0) result++;
			}
		}
		cout << "#" << t << " " << result << "\n";
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}