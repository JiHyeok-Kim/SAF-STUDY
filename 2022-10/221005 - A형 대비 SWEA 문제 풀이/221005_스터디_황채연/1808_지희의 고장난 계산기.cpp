#include <iostream>
#include <vector>
#include <string>
using namespace std;

int T, X;
vector<int> in;
vector<string> pick;
int mini = 21e8;

void DFS(int cnt, int endSize, string temp) {
	if (cnt == endSize) {
		int target = stoi(temp);
		if (temp[0] != '0' && target <= X && X % target == 0) pick.push_back(temp);
		return;
	}

	for (int i = 0; i < in.size(); ++i) {
		char cur = in[i] + '0';
		DFS(cnt + 1, endSize, temp + cur);
	}
}

int getXSize(int tar) {
	int len = 1;
	while (1) {
		if (tar / 10 == 0) break;
		tar /= 10;
		len++;
	}
	return len;
}

void minDFS(long long val, int click_num, int sp) {
	if (val > X) return;
	if (val == X) {
		if (mini > click_num) mini = click_num;
		return;
	}

	for (int i = sp; i < pick.size(); ++i) {
		int tar = stoi(pick[i]);
		if (tar == 1) continue;
		minDFS(val * tar, click_num + pick[i].size() + 1, i);
	}
}

int Solve() {
	int Xsize = getXSize(X);
	for (int i = 1; i <= Xsize; ++i) {
		DFS(0, i, "");
	}

	minDFS(1, 0, 0);
	if (mini == 0) return 2; // case 54 => 한번에 값이 나오는 경우
	if (mini == 21e8) return -1;
	return mini;
}

void init() {
	mini = 21e8;
	in.clear();
	pick.clear();
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		init();
		for (int i = 0; i < 10; ++i) {
			int num;
			cin >> num;
			if (num == 1) in.push_back(i);
		}
		cin >> X;

		int ret = Solve();
		cout << "#" << tc << " " << ret << "\n";
	}
	return 0;
}