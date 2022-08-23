#include <iostream>
#include <cmath>
using namespace std;

struct tower {
	int y;
	int x;
	int r;
};

int vect[3000];
tower arr[3000];
int groupCnt;

int Find(int now) {
	if (vect[now] == now) return now;

	return vect[now] = Find(vect[now]);
}
void UNION(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);

	if (pA == pB) return;
	vect[pB] = pA;
	groupCnt--;
}

int main() {
	int testCase;
	cin >> testCase;
	for (int t = 0; t < testCase; t++) {
		int n;
		cin >> n;
		groupCnt = n;

		for (int i = 0; i < n; i++) {
			vect[i] = i;
		}

		for (int i = 0; i < n; i++) {
			int y, x, r;
			cin >> arr[i].y >> arr[i].x >> arr[i].r;
		}

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				double dist = pow((arr[i].y - arr[j].y), 2) + pow((arr[i].x - arr[j].x), 2);
				if (dist <= pow((arr[i].r + arr[j].r), 2)) {
					if (Find(i) == Find(j)) continue;
					UNION(i, j);
				}
			}
		}

		cout << groupCnt << '\n';
	}
	return 0;
}