// ���μ��� �����ϱ� 
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <algorithm>

using namespace std;

int map[13][13], N;
int MaxCore = -21e8, MinLine = 21e8;
typedef struct {
	int y, x;
} str;
vector<str> vec;
const int dy[] = { 0, 0, -1, 1, 0 };
const int dx[] = { -1, 1, 0, 0, 0 };

void changeMap(str now, int dir, int ver) { // map change func

	for (int i = 1; i < N; i++) {
		int ny = now.y + (dy[dir] * i);
		int nx = now.x + (dx[dir] * i);
		if (ny >= N || ny < 0 || nx >= N || nx < 0) break;
		map[ny][nx] = ver;
	}
	
	return;
}

int isValid(str now, int dir) { // ValidCheck func (�� �� �־� ?)
	int sum = 0;

	for (int i = 1; i < N; i++) {
		int ny = now.y + (dy[dir] * i);
		int nx = now.x + (dx[dir] * i);
		if (ny >= N || ny < 0 || nx >= N || nx < 0) break;
		if (map[ny][nx] != 0) return 0;
		sum++;
	}

	return sum; // �� �� ������ �󸶳� �� �� �ִ��� ��ȯ 
}

void dfs(int cnt, int core, int line) { // DFS func
	if (cnt == vec.size()) { // ���� ���� 
		// ...
		if (core > MaxCore) { // ����
			MaxCore = core;
			MinLine = line;
		}
		if (core == MaxCore) {
			if (line < MinLine) MinLine = line;
		}

		return;
	}

	str now = vec[cnt];

	for (int dir = 0; dir < 5; dir++) { // 4���� + ���ڸ� 
		if(dir != 4) {
			int plus = isValid(now, dir);
			if (plus > 0) {
				changeMap(now, dir, 2);
				dfs(cnt + 1, core + 1, line + plus);
				changeMap(now, dir, 0);
			}
		}
		else dfs(cnt + 1, core, line);
	}
}

void init() { // ���� �ʱ�ȭ �Լ�
	map[13][13] = { 0 };
	N = 0;
	MaxCore = -21e8;
	MinLine = 21e8;
	vec.clear();
}

int main() {
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) { // test case
		init(); // ���� �ʱ�ȭ func
		cin >> N;

		for (int y = 0; y < N; y++) { // map �ʱ�ȭ
			for (int x = 0; x < N; x++) {
				cin >> map[y][x];
				if (y == 0 || y == N - 1 || x == 0 ||
					x == N - 1) continue;
				if (map[y][x] == 1) vec.push_back({ y, x });
			}
		}

		dfs(0, 0, 0);

		cout << "#" << tc + 1 << " " << MinLine << endl;
	}

	return 0;
}