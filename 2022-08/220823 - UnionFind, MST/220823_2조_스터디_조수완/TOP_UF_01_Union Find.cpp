#include <iostream>
using namespace std;

int parent[1100], N, Q;

int Find(int now) {
	if (parent[now] == now) return now;
	return parent[now] = Find(parent[now]);
}

void Union(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);
	if (pA == pB) return;
	parent[pB] = pA;
}

int main() {
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) parent[i] = i;
	for (int i = 0; i < Q; i++) {
		int K, A, B;
		cin >> K >> A >> B;
		if (K == 1) Union(A, B);
		if (K == 0) {
			if (Find(A) == Find(B)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}