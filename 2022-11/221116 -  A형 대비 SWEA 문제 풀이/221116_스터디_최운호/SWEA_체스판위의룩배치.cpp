#include <iostream>
using namespace std;

bool solve() {
	int rookCnt = 0;
	char map[8][8];
	bool cnt[8][8] = { false };

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'O') {
				for (int k = 0; k < 8; k++) {
					cnt[i][k] = true;
					cnt[k][j] = true;
				}
				cnt[i][j] = false;
				rookCnt++;
			}
		}
	}

	if (rookCnt != 8) return false;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (map[i][j] == 'O' && cnt[i][j]) return false;
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		string answer;
		if (solve()) cout << "#" << t << " yes" << '\n';
		else cout << "#" << t << " no" << '\n';
	}

	return 0;
}