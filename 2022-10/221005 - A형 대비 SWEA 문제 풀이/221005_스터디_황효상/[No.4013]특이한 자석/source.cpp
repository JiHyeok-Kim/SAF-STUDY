#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>


using namespace std;

int gear[5][8];
int gear_idx[5];
int T;
int K;
int mov[2] = { 1,7 };


int left_gear_judge(int now_idx) {

	int left = gear[now_idx][(gear_idx[now_idx] + 6) % 8];
	int left_gear_info = gear[now_idx - 1][(gear_idx[now_idx - 1] + 2) % 8];
	if (left != left_gear_info) {
		return 1;
	}
	
	return 0;
}

int right_gear_judge(int now_idx) {
	int right = gear[now_idx][(gear_idx[now_idx] + 2) % 8];
	int right_gear_info = gear[now_idx + 1][(gear_idx[now_idx + 1] + 6) % 8];
	if (right != right_gear_info) {
		return 1;
	}

	return 0;

}

void turn(int before_idx, int now_idx,int d) {
	if (before_idx == now_idx) {
		if (now_idx != 1) {
			if (left_gear_judge(now_idx)) {
				turn(now_idx, now_idx - 1, !d);
			}
		}
			
		if (now_idx != 4) {
			if (right_gear_judge(now_idx)) {	
				turn(now_idx, now_idx + 1, !d);
			}
		}
	}
	else {
		if (before_idx > now_idx) {
			if (now_idx != 1 && left_gear_judge(now_idx)) {
				turn(now_idx, now_idx - 1, !d);
			}
		}
		else {
			if (now_idx != 4 && right_gear_judge(now_idx)) {
					turn(now_idx, now_idx + 1, !d);
			}
		}
	}
		gear_idx[now_idx] = (gear_idx[now_idx] + mov[d]) % 8;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	cin >> T;
	for(int t = 1;  t <= T; ++t){
		cin >> K;
		for (int a = 1; a <= 4; ++a) {
			for (int b = 0; b < 8; ++b) {
				cin >> gear[a][b];
			}
		}

		for (int q = 0; q < K; ++q) {
			int idx, arrow;
			cin >> idx >> arrow;
			if (arrow == -1)
				arrow = 0;
			turn(idx,idx, arrow);
		}
		int tot = gear[1][gear_idx[1]] + gear[2][gear_idx[2]]*2 + gear[3][gear_idx[3]]*4 + gear[4][gear_idx[4]]*8;
		cout << "#"<<t<<" "<<tot << "\n";
		for (int a = 1; a <= 4; ++a) {
			gear_idx[a] = 0;
		}
	}

}
