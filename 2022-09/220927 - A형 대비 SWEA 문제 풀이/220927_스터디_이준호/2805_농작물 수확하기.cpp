#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n, ans;
string map[50];

void solve() {
	int cut = n / 2;
	int spread = 0;
	int start, end;
	ans = 0;

	for (int y = 0; y < n; y++) {
		start = cut - spread;
		end = cut + spread;

		for (int x = start; x <= end; x++) {
			ans += map[y][x] - '0';
		}

		if (y >= cut) spread--;
		else spread++;
	}

}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;

	for (int tc = 1; tc <= tcCnt; tc++) {
		
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> map[i];
		}
		solve();

		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}