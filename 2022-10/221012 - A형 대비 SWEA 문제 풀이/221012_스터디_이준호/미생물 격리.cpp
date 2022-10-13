#include <iostream>
#include <queue>
#include <cstring>
using namespace std;


int N, Fin, K, ans;
// 아래 위 우측 좌측
int ditY[5] = { 0,1,-1,0,0 };
int ditX[5] = { 0,0,0,1,-1 };
struct Node {
	int num;
	int dr;
};

Node map[110][110];
Node temp[110][110];

priority_queue<Node> pq;
bool operator < ( Node A, Node B ) {
	return A.num > B.num;
}

void init() {
	ans = 0;
	for (int y = 0; y < 110; y++) {
		for (int x = 0; x < 110; x++) {
			map[y][x].num = 0;
			map[y][x].dr = 0;
		}
	}
}

void input() {
	int a, b, c, d;
	cin >> N >> Fin >> K;
	for (int i = 0; i < K; i++) {
		cin >> a >> b >> c >> d;
		map[a][b].num = c;
		map[a][b].dr = d;
	}
}

void cntCome(int y, int x) {
	for (int i = 1; i <= 4; i++) {
		int ny = y + ditY[i];
		int nx = x + ditX[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (map[ny][nx].dr == i)
		{
			pq.push({ map[ny][nx].num, map[ny][nx].dr });
		}
	}
}

void HalfTurn() {
	// 위, 아래 행
	for (int y = 0; y < N; y += N - 1) {
		for (int x = 1; x < N - 1; x++) {
			temp[y][x].num /= 2;
			if (y == 0 && temp[y][x].num != 0) temp[y][x].dr = 2;
			else if (y == N - 1 && temp[y][x].num != 0) temp[y][x].dr = 1;
		}
	}
	// 왼쪽, 오른쪽 열
	for (int x = 0; x < N; x += N - 1) {
		for (int y = 1; y < N - 1; y++) {
			temp[y][x].num /= 2;
			if (x == 0 && temp[y][x].num != 0) temp[y][x].dr = 4;
			if (x == N - 1 && temp[y][x].num != 0) temp[y][x].dr = 3;
		}
	}
}

void getAns() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x].num > 0) {
				ans += map[y][x].num;
			}
		}
	}
}

void solve() {

	for (int i = 0; i < Fin; i++) {
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) {

				cntCome(row, col); // 기준 셀로 올 수 있는 것 pq에 푸시
				if (pq.size() == 0) continue; // 해당 셀로 오는 것이 하나도 없다면 다음 셀로 진행
				else {
					// 하나라면 temp 맵에 옮겨 아니라면 가장 큰 놈이 다 먹기
					while (!pq.empty()) {
						Node Coord = pq.top();
						pq.pop();
						temp[row][col].num += Coord.num;
						temp[row][col].dr = Coord.dr;
					}

				}

			}
		}
		// 맵 한 번 훑었을때 테두리에 있는 애들만 방향 바꾸고 하프
		HalfTurn();
		memcpy(map, temp, sizeof(temp));
		memset(temp, 0, sizeof(temp));
	}
	
	getAns();
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