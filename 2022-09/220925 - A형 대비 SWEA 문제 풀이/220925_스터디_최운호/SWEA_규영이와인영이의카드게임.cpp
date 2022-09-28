#include <iostream>
#include <vector>
using namespace std;
int kyu[9];
int in[9];
int used[9];
int card[9];
int win;
int defeat;

void dfs(int lev, int opp, int my) {
	if (lev == 9) {
		if (opp > my) win++;
		else defeat++;
		return;
	}

	for (int i = 0; i < 9; i++) {
		int flag = 0;
		if (used[i] == 1) continue;
		used[i] = 1;
		in[lev] = card[i];
		int score = in[lev] + kyu[lev];
		if (in[lev] > kyu[lev]) my += score;
		else {
			opp += score;
			flag = 1;
		}
		dfs(lev + 1, opp, my);
		if (flag) opp -= score;
		else my -= score;
		in[lev] = 0;
		used[i] = 0;
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int dat[19] = { 0 };
		win = 0;
		defeat = 0;
		for (int i = 0; i < 9; i++) {
			cin >> kyu[i];
			dat[kyu[i]] = 1;
		}

		int idx = 0;
		for (int i = 1; i < 19; i++) {
			if (dat[i] == 1) continue;
			card[idx] = i;
			idx++;
		}

		dfs(0, 0, 0);

		cout << "#" << t << " " << win << " " << defeat << '\n';
	}
	return 0;
}