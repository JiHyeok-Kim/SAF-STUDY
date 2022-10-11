#include <iostream>
using namespace std;

int N, ans;
int map[5100];
int inter[5100];
int flag;

void init() {
	ans = 0;
	for (int i = 0; i < 5100; i++) {
		map[i] = 0;
		inter[i] = 0;
	}
}
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
		inter[i] = map[i] - 1;
	}
}

void solve() {
	
	for (int tar = N - 1; tar >= 2 ; tar--) {
		flag = 0;
		for (int idx = 1; idx <= tar - 1; idx++) {
			if (inter[tar] % inter[idx] == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) ans++;
	}
	ans++;
	
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
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