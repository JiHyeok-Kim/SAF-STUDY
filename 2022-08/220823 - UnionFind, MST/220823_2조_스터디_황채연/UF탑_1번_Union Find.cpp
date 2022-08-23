#include <iostream>
using namespace std;

int N, Q;
int parent[1001];

int Find(int tar) {
	if (parent[tar] == 0) return tar;
	int ret = Find(parent[tar]);
	parent[tar] = ret;
	return ret;
}

void Union(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);
	if (pA == pB) return;
	parent[pB] = pA;
}
int main()
{
	cin >> N >> Q;
	while (Q--) {
		int K, A, B;
		cin >> K >> A >> B;
		if (K == 1) {
			Union(A, B);
		}
		if (K == 0) {
			if (Find(A) == Find(B)) cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;
}