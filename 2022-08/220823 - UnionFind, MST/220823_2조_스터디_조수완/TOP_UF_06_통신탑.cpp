#include <iostream>
#include <vector>
using namespace std;
struct Node {
	int y, x, r;
	int idx;
};
int parent[3300], T, N;
int dat[3300], cnt;

int Find(int now) {
	if (parent[now] == now) return now;
	return parent[now] = Find(parent[now]);
}

void Union(Node A, Node B) {
	int pA = Find(A.idx);
	int pB = Find(B.idx);
	if (pA == pB) return;
	parent[pB] = pA;
	dat[pA] += dat[pB];
	dat[pB] = 0;
}

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		vector<Node> list = { {0,0,0,0} };
		cin >> N;
		for (int i = 1; i <= N; i++) {
			parent[i] = i;
			dat[i] = 1;
		}
		cnt = 0;
		for (int i = 1; i <= N; i++) {
			int y, x, r;
			cin >> y >> x >> r;
			list.push_back({ y,x,r,i });
			for (int j = 1; j < i; j++) {
				if (((list[i].y - list[j].y) * (list[i].y - list[j].y)) + ((list[i].x - list[j].x) * (list[i].x - list[j].x)) <= ((list[i].r + list[j].r) * (list[i].r + list[j].r))) {
					Union(list[i], list[j]);
				}
			}
		}
		for (int i = 1; i <= N; i++) {
			if (dat[i] > 0) cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}