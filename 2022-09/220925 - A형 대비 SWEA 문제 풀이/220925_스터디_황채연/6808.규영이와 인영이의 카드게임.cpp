#include <iostream>
using namespace std;

int T;
int CARD[19];
bool visited[19];
int v[10], v2[10];
int ret_win = 0, ret_draw = 0;
int total_case = 1;

void DFS(int cnt, int win, int lose) {
	if (cnt == 9) {
		if (win > lose) ret_win++;
		if (win == lose) ret_draw++;
		return;
	}

	for (int i = 0; i < 9; ++i) {
		int card = v2[i];
		if (visited[card] == true) continue;
		visited[card] = true;
		if (v[cnt] > card) {
			DFS(cnt + 1, win + (v[cnt] + card), lose);
		}
		if (v[cnt] < card) {
			DFS(cnt + 1, win, lose + (v[cnt] + card));
		}
		visited[card] = false;
	}
}

void Solve(int tc) {
	DFS(0, 0, 0);
	cout << "#" << tc << " " << ret_win << " " << total_case - ret_win - ret_draw << "\n";
}

void init() {
	ret_win = 0;	ret_draw = 0;
	total_case = 1;

	for (int i = 1; i <= 18; ++i) {
		CARD[i] = 0;
	}

	for (int i = 1; i <= 9; ++i) {
		total_case *= i;
	}
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		init();
		for (int i = 0; i < 9; ++i) {
			cin >> v[i];
			CARD[v[i]] = 1;
		}

		int start = 0;
		for (int i = 1; i <= 18; ++i) {
			if (CARD[i] == 1) continue;
			v2[start++] = i;
		}

		Solve(tc);
	}
	return 0;
}