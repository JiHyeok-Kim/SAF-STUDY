#include <iostream>
#include <cstring>
using namespace std;

int boy[9];
int girl[9];
int dat[20];
int path[9];
int used[9];
int win, lose;

void run(int boysum, int girlsum, int lev) {
	if (lev == 9) {
		
		if (boysum > girlsum) win++;
		else lose++;

		return;
	}

	for (int i = 0; i < 9; i++) {
		if (used[i] == 1) continue;
		path[lev] = girl[i];
		used[i] = 1;

		if (boy[lev] > path[lev]) {
			boysum += boy[lev] + path[lev];
		}
		else {
			girlsum += boy[lev] + path[lev];
		}
		run(boysum, girlsum, lev + 1);

		if (boy[lev] > path[lev]) {
			boysum -= boy[lev] + path[lev];
		}
		else {
			girlsum -= boy[lev] + path[lev];
		}
		
		used[i] = 0;
	}

}


int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;

	for (int tc = 1; tc <= tcCnt; tc++) {
		memset(dat, 0, sizeof(dat));
		win = 0; lose = 0;

		for (int i = 0; i < 9; i++) {
			cin >> boy[i];
			dat[boy[i]]++;
		}
		int idx = 0;
		for (int i = 1; i < 19; i++) {
			if (dat[i] == 0) {
				girl[idx] = i;
				idx++;
			}
		}

		run(0, 0, 0);
		cout << "#" << tc << " " << win << " " << lose << "\n";
	}

	return 0;
}