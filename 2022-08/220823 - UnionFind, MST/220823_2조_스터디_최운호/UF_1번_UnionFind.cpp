#include <iostream>
using namespace std;

int n, q;

int vect[1000];

int Find(int now) {
	if (vect[now] == 0) return now;
	int ret = Find(vect[now]);
	vect[now] = ret;
	return ret;
}
void UNION(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);

	vect[pB] = pA;
}

int main() {
	cin >> n >> q;

	for (int i = 0; i < q; i++) {
		int type, a, b;
		cin >> type >> a >> b;
		if (type == 1) {
			if (Find(a) == Find(b)) continue;
			UNION(a, b);
		}
		if (type == 0) {
			if (Find(a) == Find(b)) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}

	return 0;
}