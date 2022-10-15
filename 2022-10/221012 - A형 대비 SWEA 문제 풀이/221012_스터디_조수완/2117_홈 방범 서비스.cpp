#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
struct Node { int y, x; };
int map[25][25], N, M, result, maxDist;
int distCost[450], distHouse[450];
vector<Node> house;
void setCost() {
	for (int i = 1; i <= N+1; i++) {
		distCost[i] = (i * i) + (i - 1) * (i - 1);
	}
}

void input() {
	cin >> N >> M;
	house.clear();
	result = 0;
	maxDist = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] == 1) house.push_back({ y,x });
		}
	}
	setCost();
}
void solution() {
	for (int sy = 0; sy < N; sy++) {
		for (int sx = 0; sx < N; sx++) {
			maxDist = 0;
			memset(distHouse, 0, sizeof(distHouse));
			for (int j = 0; j < house.size(); j++) {
				int dist = abs(house[j].y - sy) + abs(house[j].x - sx) + 1;
				for (int k = dist; k <= N+1; k++) distHouse[k]++;
				maxDist = max(dist, maxDist);
			}
			int xhnum = distHouse[0];
			for (int j = 1; j <= maxDist; j++) {
				if (distHouse[j] == xhnum)continue;
				int cost1 = M * distHouse[j] - distCost[j];
				if (cost1 < 0) continue;
				result = max(result, distHouse[j]);
				xhnum = distHouse[j];
				if (result == house.size()) break;
			}
		}
		if (result == house.size()) break;
	}
}

void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		solution();
		cout << "#" << t << " " << result << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}