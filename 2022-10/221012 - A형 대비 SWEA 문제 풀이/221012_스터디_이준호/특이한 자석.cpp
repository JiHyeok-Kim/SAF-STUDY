#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int k, a, b;
int map[5][9];
int meet[7];
int ans;

struct Node {
	int num, bang;
};
queue<Node> q;

void init() {
	ans = 0;
	for (int y = 1; y <= 4; y++) {
		for (int x = 1; x <= 8; x++) {
			map[y][x] = 0;
		}
	}
}

void input() {
	cin >> k;
	for (int y = 1; y <= 4; y++) {
		for (int x = 1; x <= 8; x++) {
			cin >> map[y][x];
		}
	}

	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		q.push({ a,b });
	}
}

void cir(int tar) {
	int temp = map[tar][8];
	for (int x = 7; x >= 1; x--) {
		map[tar][x + 1] = map[tar][x];
	}
	map[tar][1] = temp;
}

void Rcir(int tar) {
	int temp = map[tar][1];
	for (int x = 2; x <= 8; x++) {
		map[tar][x - 1] = map[tar][x];
	}
	map[tar][8] = temp;
}

void setMeet() {
	// 접합면 6개 1차원 배열에 넣기
	int a = 1;
	for (int i = 1; i <= 6; i++) {
		if (i % 2 == 1) {
			meet[i] = map[a][3];
			a++;
		}
		else meet[i] = map[a][7];
	}
}

void howCir(int circle[]) {
	for (int i = 1; i <= 4; i++) {
		if (circle[i] == 1) cir(i);
		else if (circle[i] == -1) Rcir(i);
	}
}

void solve() {

	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		int circle[5] = { 0 };
		int tar = now.num;
		int way = now.bang;
		
		setMeet();

		circle[tar] = way;

		if (tar == 1) {
			int idx = 2;
			for (int i = 1; i <= 5; i += 2) {
				if (meet[i] == meet[i + 1]) break;
				circle[idx] = -circle[idx - 1];
				idx++;
			}
			howCir(circle);
		}
		else if (tar == 4) {
			int idx = 3;
			for (int i = 6; i >= 2; i -= 2) {
				if (meet[i] == meet[i - 1]) break;
				circle[idx] = -circle[idx + 1];
				idx--;
			}
			howCir(circle);
		}
		else if (tar == 2) {
			int flag = 0;
			if (meet[2] != meet[1]) circle[1] = -circle[2];
			if (meet[3] != meet[4]) {
				flag = 1;
				circle[3] = -circle[2];
			}
			if (flag == 1 && meet[5] != meet[6]) circle[4] = -circle[3];
			howCir(circle);
		}

		else if (tar == 3) {
			int flag = 0;
			if (meet[5] != meet[6]) circle[4] = -circle[3];
			if (meet[4] != meet[3]) {
				flag = 1;
				circle[2] = -circle[3];
			}
			if (flag == 1 && meet[2] != meet[1]) circle[1] = -circle[2];
			howCir(circle);
		}
	}
	for (int y = 1; y <= 4; y++) {
		if (map[y][1] == 1) {
			ans += pow(2,(y - 1));
		}
	}

}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		init();
		input();
		solve();

		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}