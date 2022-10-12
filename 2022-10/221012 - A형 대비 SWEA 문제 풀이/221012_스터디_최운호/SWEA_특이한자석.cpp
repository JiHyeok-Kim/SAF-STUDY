#include <iostream>
using namespace std;

int k;
int magnet[5][8];
int direction[5];

void turn(int idx, int dir) {
	if (dir == 1) {
		int tmp = magnet[idx][7];
		for (int i = 6; i >= 0; i--) {
			magnet[idx][i + 1] = magnet[idx][i];
		}
		magnet[idx][0] = tmp;
		direction[idx] = 0;
	}
	else if (dir == -1) {
		int tmp = magnet[idx][0];
		for (int i = 1; i < 8; i++) {
			magnet[idx][i - 1] = magnet[idx][i];
		}
		magnet[idx][7] = tmp;
		direction[idx] = 0;
	}
}

void search(int st) {
	if (st - 1 >= 1 && direction[st-1] == 0) {
		if (magnet[st][6] != magnet[st - 1][2]) {
			direction[st - 1] = direction[st] * (-1);
			search(st - 1);
		}
	}
	if (st + 1 < 5 && direction[st+1] == 0) {
		if (magnet[st][2] != magnet[st + 1][6]) {
			direction[st + 1] = direction[st] * (-1);
			search(st + 1);
		}
	}
}

int getScore() {
	int result = 0;
	if (magnet[1][0] == 1) result += 1;
	if (magnet[2][0] == 1) result += 2;
	if (magnet[3][0] == 1) result += 4;
	if (magnet[4][0] == 1) result += 8;

	return result;
}


int main()
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> k;
		int score = 0;
		for (int i = 1; i <= 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> magnet[i][j];
			}
		}

		for (int i = 0; i < k; i++) {
			int n, d;
			cin >> n >> d;
			direction[n] = d;
			search(n);
			for (int j = 1; j <= 4; j++) {
				if (direction[j] == 0) continue;
				turn(j, direction[j]);
			}
		}
		score = getScore();

		cout << "#" << t << " " << score << '\n';
	}
	return 0;
}