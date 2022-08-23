#include <iostream>
using namespace std;

int vect[1000];

int n;
int map[1000][1000];

int Find(int now) {
	if (vect[now] == 0) return now;
	int ret = Find(vect[now]);
	vect[now] = ret;
	return ret;
}

void UNION(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);

	if (pA == pB) return;

	vect[pB] = pA;
}

int main() {
	cin >> n;

	int idx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (j < idx) continue;
			if (map[i][j] == 0) continue;
			if (Find(i) == Find(j)) {
				cout << "WARNING";
				return 0;
			}
			UNION(i, j);
		}
		idx++;
	}
	cout << "STABLE";
	return 0;
}