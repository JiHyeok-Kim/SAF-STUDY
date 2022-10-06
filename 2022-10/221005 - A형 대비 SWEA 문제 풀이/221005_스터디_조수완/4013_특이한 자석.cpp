#include <iostream>
#include <vector>
using namespace std;

int K;
vector<int> gear[5];
int dat[5];

int getScore() {
	int score = 0;
	score += 1 * gear[1][0];
	score += 2 * gear[2][0];
	score += 4 * gear[3][0];
	score += 8 * gear[4][0];
	return score;
}
void CCW(int idx) {
	gear[idx].push_back(gear[idx][0]);
	gear[idx].erase(gear[idx].begin());
}
void CW(int idx) {
	gear[idx].insert(gear[idx].begin(), gear[idx][gear[idx].size() - 1]);
	gear[idx].pop_back();
}
void left(int tar, int dir) {
	int xtar = tar;
	int xdir = dir;
	int ndir = dir;
	for (int i = 1; i <= 4; i++) {
		int ntar = tar - i;
		if (ntar < 1)return;
		if (gear[xtar][6] == gear[ntar][2]) return;
		if (xdir == 1) ndir = -1;
		else ndir = 1;
		dat[ntar] = ndir;
		xtar = ntar;
		xdir = ndir;
	}
}
void right(int tar, int dir) {
	int xtar = tar;
	int xdir = dir;
	int ndir = dir;
	for (int i = 1; i <= 4; i++) {
		int ntar = tar + i;
		if (ntar > 4) return;
		if (gear[xtar][2] == gear[ntar][6]) return;
		if (xdir == 1) ndir = -1;
		else ndir = 1;
		dat[ntar] = ndir;
		xtar = ntar;
		xdir = ndir;
	}
}
void setGear() {
	for (int i = 1; i <= 4; i++) {
		if (dat[i] == 0) continue;
		if (dat[i] == 1) CW(i);
		if (dat[i] == -1) CCW(i);
	}
}
int sol () {
	for (int i = 0; i < K; i++) {
		for (int j = 1; j <= 4; j++) dat[j] = 0;
		int tar, dir;
		cin >> tar >> dir;
		dat[tar] = dir;
		left(tar, dir);
		right(tar, dir);
		setGear();
	}
	int score = getScore();
	return score;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int T = 0;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		for (int i = 1; i <= 4; i++) gear[i].clear();
		cin >> K;
		for (int i = 1; i <= 4; i++) {
			for (int j = 0; j < 8; j++) {
				int val;
				cin >> val;
				gear[i].push_back(val);
			}
		}
		int score = sol();
		cout << "#" << t << " " << score << "\n";
	}
	return 0;
}