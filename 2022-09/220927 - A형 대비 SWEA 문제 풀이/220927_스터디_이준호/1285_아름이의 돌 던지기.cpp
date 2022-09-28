#include <iostream>
using namespace std;

int map[1010];
int dat[100010];

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int tcCnt;
	int n, point, cnt;

	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		cin >> n;
		memset(dat, 0, sizeof(dat));
		for (int i = 0; i < n; i++) {
			cin >> map[i];
			if (map[i] < 0) dat[-map[i]]++;
			else dat[map[i]]++;
		}

		for (int i = 0; i <= 100000; i++) {
			if (dat[i] > 0) {
				point = i;
				cnt = dat[i];
				break;
			}
		}
		
		cout << "#" << tc << " " << point << " " << cnt << "\n";
	}

	return 0;
}