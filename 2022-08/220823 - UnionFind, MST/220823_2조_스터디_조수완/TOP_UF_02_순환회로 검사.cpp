#include <iostream>
using namespace std;

int map[1100][1100], N;
int parent[1100];
int Find(int now) {
	if (parent[now] == now) return now;
	return parent[now] = Find(parent[now]);
}

int Union(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);
	if (pA == pB) return 1;
	parent[pB] = pA;
	return 0;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) parent[i] = i;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}
	for (int y = 0; y < N; y++) {
		for (int x = y; x < N; x++) {
			if (map[y][x] == 1) {
				if (Union(y, x)) {
					cout << "WARNING";
					return 0;
				}
			}
		}
	}
	cout << "STABLE";
	return 0;
}