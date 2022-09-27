#include <iostream>
using namespace std;

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int tcCnt, n, k;
	int map[20][20] = {0};
	cin >> tcCnt;
	
	for (int tc = 1; tc <= tcCnt; tc++) {
		cin >> n >> k;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				cin >> map[y][x];
			}
		}

		int cnt;
		int ans = 0;
		int flag = 0;
		for (int y = 0; y < n; y++) {
			flag = 0;
			cnt = 0;
			for (int x = 0; x < n; x++) {
				if (map[y][x] == 0) cnt = 0;
				else cnt++;

				if (flag == 1 && cnt == 0) ans++;
				flag = 0;
				if (cnt == k) flag = 1;
				
			}
			if (cnt == k) ans++;
		}

		
		for (int x = 0; x < n; x++) {
			flag = 0;
			cnt = 0;
			for (int y = 0; y < n; y++) {
				if (map[y][x] == 0) cnt = 0;
				else cnt++;

				if (flag == 1 && cnt == 0) ans++;
				flag = 0;
				if (cnt == k) flag = 1;
			}
			if (cnt == k) ans++;
		}

		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}