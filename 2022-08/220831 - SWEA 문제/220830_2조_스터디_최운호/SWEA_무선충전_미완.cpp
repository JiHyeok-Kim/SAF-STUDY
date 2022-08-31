#include <iostream>
#include <vector>
using namespace std;

struct charger {
	int x;
	int y;
	int c;
	int p;
	int now;
};

struct pos {
	int y;
	int x;
};

vector<int> arr[11][11];

pos h1 = { 1,1 };
pos h2 = { 10,10 };

int M, A;
int dir1[101];
int dir2[101];

int result;

charger cg[8];

int dx[5] = { 0,0,1,0,-1 };
int dy[5] = { 0,-1,0,1,0 };

void init(int x, int y, int d, int idx) {

	for (int i = y - d; i <= y + d; i++) {
		for (int j = x - d; j <= x + d; j++) {
			if (i < 1 || j < 1 || i >= 11 || j >= 11) continue;
			if (d < abs(i - y) + abs(j - x)) continue;
			arr[i][j].push_back(idx);
		}
	}
	return;
}

void run(int idx) {

	if (idx > 0) {
		h1.x = h1.x + dx[dir1[idx]];
		h1.y = h1.y + dy[dir1[idx]];

		h2.x = h2.x + dx[dir2[idx]];
		h2.y = h2.y + dy[dir2[idx]];
	}
	vector<int> h1Now;
	vector<int> h2Now;
	
	for (int loop : arr[h1.y][h1.x]) {
		h1Now.push_back(loop);
	}
	for (int loop : arr[h2.y][h2.x]) {
		h2Now.push_back(loop);
	}

	if (h1Now.size() == 0 && h2Now.size() == 0) return;

	else if (h1Now.size() == 1 && h2Now.size() == 0) {
		result += cg[h1Now[0]].p;
	}

	else if (h1Now.size() == 0 && h2Now.size() == 1){
		result += cg[h2Now[0]].p;
	}
	else {
		int maxVal = 0;
		for (int i : h1Now) {
			int val = 0;
			cg[i].now++;
			for (int j : h2Now) {
				cg[j].now++;
				val += cg[i].p / cg[i].now;
				val += cg[j].p / cg[j].now;
				maxVal = max(val, maxVal);
				cg[j].now--;
			}
			cg[i].now--;
		}
		result += maxVal;
	}
	

	return;
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		cin >> M >> A;
		result = 0;

		h1 = { 1,1 };
		h2 = { 10,10 };

		for (int i = 1; i <= M; i++) {
			int dir;
			cin >> dir;
			dir1[i] = dir;
		}

		for (int i = 1; i <= M; i++) {
			int dir;
			cin >> dir;
			dir2[i] = dir;
		}

		for (int i = 0; i < A; i++) {
			int x, y, c, p;
			cin >> x >> y >> c >> p;
			cg[i] = { x,y,c,p,0 };
			init(x, y, c, i);
		}

		for (int i = 0; i <= M; i++) {
			run(i);
		}

		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				if (arr[i][j].size() == 0) continue;
				while (arr[i][j].size() > 0) arr[i][j].pop_back();
			}
		}

		cout << "#" << t << " " << result << '\n';
	}

	return 0;
}