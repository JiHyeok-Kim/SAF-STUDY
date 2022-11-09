#include <iostream>
using namespace std;
int T;
int N, M, arr[10010];
void solve() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++)cin >> arr[i];
		int r = 0, l = 0, sum = arr[0], cnt = 0;
		if (sum == M)cnt++;
		while (l <= r) {
			if (sum > M) {
				l++; 
				sum -= arr[l-1]; 
			}
			else { 
				r++; 
				if (r >= N)break;
				if(r<N)sum += arr[r];
			}
			if (sum == M)cnt++;
		}
		cout << "#" << t << " " << cnt << "\n";
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