#include <iostream>
#include <vector>
using namespace std;

int T, N;
int parent[3001];
int towerCnt, groupCnt;

typedef struct {
	int y, x;
	int round;
}POSI;
vector <POSI> v;

int Find(int tar) {
	if (parent[tar] == tar) return tar;
	int ret = Find(parent[tar]);
	parent[tar] = ret;
	return ret;
}

void Union(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);
	if (pA == pB) return;
	parent[pB] = pA;
	groupCnt++;
}

int inDist(POSI cur, POSI next) {
	int Rdist = (cur.round + next.round) * (cur.round + next.round);
	int real = (cur.y - next.y)*(cur.y - next.y) + (cur.x - next.x) * (cur.x - next.x);
	if (real <= Rdist) return 1;
	return 0;
}

int getResult() {
	for (int i = 0; i < v.size(); ++i) {
		POSI cur = v[i];
		for (int j = i + 1; j < v.size(); ++j) {
			POSI next = v[j];
			if (!inDist(cur, next)) continue;
			if (Find(i) == Find(j)) continue;
			Union(i, j);
		}
	}
	return towerCnt - groupCnt;
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		v.clear();
		groupCnt = 0;
		towerCnt = 0;
		for (int i = 0; i < 3001; ++i) parent[i] = i;

		cin >> N;
		towerCnt = N;
		for (int i = 0; i < N; ++i) {
			int x, y, R;
			cin >> x >> y >> R;
			v.push_back({ y,x,R });
		}

		int ret = getResult();
		cout << ret << "\n";
	}

	return 0;
}