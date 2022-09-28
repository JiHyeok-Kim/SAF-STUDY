#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n, k;
int map[110][3];
string grade[10] = { "A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0" };

struct Node {
	double jumsu;
	int id;
};
vector<Node> hap;

void input() {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < 3; x++) {
			cin >> map[y][x];
		}
	}
}

void calc() {
	double sum;
	for (int i = 0; i < n; i++) {
		sum = 0;
		sum += map[i][0] * 0.35 + map[i][1] * 0.45 + map[i][2] * 0.2;
		hap.push_back({ sum, i });
	}
}

bool compare(Node t, Node v) {
	return t.jumsu > v.jumsu;
}

int findtarget() {
	for (int i = 0; i < n; i++) {
		if (hap[i].id == k - 1) {
			return i;
		}
	}
}


int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	int tcCnt;
	cin >> tcCnt;

	for (int tc = 1; tc <= tcCnt; tc++) {
		cin >> n >> k;
		hap.clear();
		input();
		calc();
		sort(hap.begin(), hap.end(), compare);
		int target = findtarget();

		int gugan = n / 10;

		string ans = grade[target / gugan];
		cout << "#" << tc << " "<< ans << "\n";
	}
	return 0;
}
