#include <iostream>
#include <cstring>
using namespace std;


int N, M;
string temp;
int money, ans;
int prize[110];
string tar[110];
string juhuk[1100];
int flag;


void init() {
	ans = 0;
	for (int i = 0; i < 110; i++) {
		prize[i] = 0;
		tar[i] = "";
	}
	for (int i = 0; i < 1100; i++) {
		juhuk[i] = "";
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> temp >> money;
		tar[i] = temp;
		prize[i] = money;
	}
	for (int i = 0; i < M; i++) {
		cin >> temp;
		juhuk[i] = temp;
	}
}

void solve() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {

			for (int k = 0; k < 8; k++) {
				flag = 0;
				if (tar[y][k] != '*' && tar[y][k] != juhuk[x][k]) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				ans += prize[y];
			}

		}
	}

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