
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


int parent[1000001];

int Find(int idx) {
	if (parent[idx] == idx) {
		return idx;
	}

	return parent[idx] = Find(parent[idx]);
}

void Union(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);

	parent[pB] = pA;
}

void init() {
}
int T, N, M;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin); 
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		init();
		cin >> N >> M;
		for (int a = 1; a <= N; ++a) {
			parent[a] = a;
		}
		int command, n1, n2;
		cout << "#" << t << " ";
		for (int a = 0; a < M; ++a) {
			cin >> command >> n1 >> n2;
			if (command == 0) {
				Union(n1, n2);
			}
			else {
				int pA = Find(n1);
				int pB = Find(n2);
				if (pA == pB) {
					cout << "1";
				}
				else {
					cout << "0";
				}
			}
		}
		cout << "\n";
	}
}
