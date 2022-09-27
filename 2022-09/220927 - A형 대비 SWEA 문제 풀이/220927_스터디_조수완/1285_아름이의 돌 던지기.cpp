#include <iostream>
#include <cmath>
using namespace std;

int N, mini, cnt;

void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		mini = 21e8;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			if (abs(temp) < mini) {
				mini = abs(temp);
				cnt = 1;
			}
			else if (abs(temp) == mini) cnt++;
		}
		cout << "#" << t << " " << mini << " " << cnt << "\n";
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