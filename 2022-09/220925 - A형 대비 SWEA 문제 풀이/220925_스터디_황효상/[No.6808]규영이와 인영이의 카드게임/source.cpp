#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <string>

using namespace std;



int total_card_set[19];
int your_set[9];
int my_set[9];

int win_cnt = 0;
int lose_cnt = 0;
bool used[9];

void dfs(int deep, int gyu, int inyung) {
	if (deep == 9) {
		if (gyu > inyung)
			++win_cnt;
		else if (gyu < inyung)
			++lose_cnt;
		return;
	}

	for (int a = 0; a < 9; ++a) {
		if (used[a] == 0) {
			used[a] = 1;
			if (my_set[a] > your_set[deep]) {
				dfs(deep + 1, gyu, my_set[a] + your_set[deep] + inyung);
			}
			else {
				dfs(deep + 1, gyu + my_set[a] + your_set[deep], inyung);
			}
			used[a] = 0;
		}
	}
}
void input() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		memset(total_card_set, 0, sizeof(total_card_set));
		memset(your_set, 0, sizeof(your_set));
		memset(my_set, 0, sizeof(my_set));
		win_cnt = 0;
		lose_cnt = 0;

		for (int a = 0; a < 9; ++a) {
			cin >> your_set[a];
			total_card_set[your_set[a]] = 1;
		}
		int idx = 0;
		for (int a = 1; a <= 18; ++a) {
			if (total_card_set[a] == 0)
				my_set[idx++] = a;
		}

		dfs(0, 0, 0);
		cout << "#"<<t << " " <<win_cnt << " " << lose_cnt << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	input();

	return 0;
}
