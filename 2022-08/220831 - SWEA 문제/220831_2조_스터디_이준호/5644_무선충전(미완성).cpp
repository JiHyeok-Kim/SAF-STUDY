#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, A, ans;
int moveA[101];
int moveB[101];
int map[11][11];
int ditY[5] = { 0,-1,0,1,0 };
int ditX[5] = { 0,0,1,0,-1 };

struct Node {
	int y, x, C, P;
};
struct qNode {
    int y, x;
    int lev;
};

vector<Node> Batt;
queue<qNode> q;
void setMap(int sy, int sx, int idx, int c, int p) {
    int used[11][11] = { 0 };
    q.push({ sy,sx,0 });
    map[sy][sx].push_back({ idx,p });
    used[sy][sx] = 1;

    while (!q.empty()) {
        qNode now = q.front();
        q.pop();

        for (int i = 0; i < 5; i++) {
            int ny = now.y + ditY[i];
            int nx = now.x + ditX[i];
            int nLev = now.lev + 1;
            if (ny < 1 || nx < 1 || ny >= 11 || nx >= 11)continue;
            if (nLev == c + 1) continue;
            if (used[ny][nx] == 1)continue;
            used[ny][nx] = 1;
            q.push({ ny,nx,nLev });
            map[ny][nx].push_back({ idx,p });
        }
    }
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		cin >> M >> A;
		for (int i = 0; i < M; i++)
			cin >> moveA[i];
		for (int i = 0; i < M; i++)
			cin >> moveB[i];

		int a, b, c, d;
		for (int i = 0; i < A; i++) {
			cin >> a >> b >> c >> d;
			Batt.push_back({ a,b,c,d });
		}


		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}