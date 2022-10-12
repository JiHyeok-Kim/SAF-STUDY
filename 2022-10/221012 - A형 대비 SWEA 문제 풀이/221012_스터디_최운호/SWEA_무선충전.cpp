#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct pos {
	int y;
	int x;
	int dist;
};

int M, A;
int person[2][101];

int charger[8];
int usedCG[8];

vector<int> map[11][11];

int dy[5] = { 0,-1,0,1,0 };
int dx[5] = { 0,0,1,0,-1 };

int result;

void install(int idx, int x, int y, int maxDist)
{
	bool visited[11][11] = { 0 };
	queue<pos> q;
	q.push({ y,x,0 });
	visited[y][x] = true;

	while (!q.empty()) {
		pos now = q.front();
		q.pop();

		if (now.dist > maxDist) break;
		map[now.y][now.x].push_back(idx);

		for (int i = 1; i < 5; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 1 || nx < 1 || ny > 10 || nx > 10) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = true;
			q.push({ ny,nx,now.dist + 1 });
		}
	}
}

int getVal(vector<int> first, vector<int> second) {
	int maxi = 0;
	int firstUse, secondUse;
	for (int i = 0; i < first.size(); i++) {
		firstUse = first[i];
		usedCG[first[i]]++;
		for (int j = 0; j < second.size(); j++) {
			int sum = 0;
			secondUse = second[j];
			usedCG[second[j]]++;
			sum += charger[firstUse] / usedCG[firstUse];
			sum += charger[secondUse] / usedCG[secondUse];
			maxi = max(maxi, sum);
			usedCG[second[j]]--;
		}
		usedCG[first[i]]--;
	}

	return maxi;
}

void go() {
	int y1 = 1, x1 = 1;
	int y2 = 10, x2 = 10;

	for (int t = 0; t <= M; t++) {
		y1 += dy[person[0][t]];
		x1 += dx[person[0][t]];
		y2 += dy[person[1][t]];
		x2 += dx[person[1][t]];

		int size1 = map[y1][x1].size();
		int size2 = map[y2][x2].size();
		if (size1 == 0 && size2 == 0) continue;
		else if (size2 == 0) {
			int maxi = 0;
			for (int i = 0; i < size1; i++) {
				int val = charger[map[y1][x1][i]];
				maxi = max(val, maxi);
			}
			result += maxi;
		}
		else if (size1 == 0) {
			int maxi = 0;
			for (int i = 0; i < size2; i++) {
				int val = charger[map[y2][x2][i]];
				maxi = max(val, maxi);
			}
			result += maxi;
		}
		else {
			int val = getVal(map[y1][x1], map[y2][x2]);
			result += val;
		}
	}
}

int main()
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> M >> A;
		person[0][0] = 0;
		person[1][0] = 0;
		result = 0;
		for (int p = 0; p < 2; p++) {
			for (int i = 1; i <= M; i++) {
				cin >> person[p][i];
			}
		}
		for (int i = 0; i < A; i++) {
			int x, y, C, P;
			cin >> x >> y >> C >> P;
			charger[i] = P;
			install(i, x, y, C);
		}

		go();

		cout << "#" << t << " " << result << '\n';
		for (int i = 1; i < 11; i++) {
			for (int j = 1; j < 11; j++) {
				map[i][j].clear();
			}
		}
	}

	return 0;
}