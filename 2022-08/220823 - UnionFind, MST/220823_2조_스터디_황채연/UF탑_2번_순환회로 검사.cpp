#include <iostream>
using namespace std;

int n;
int map[1000][1000];
int parent[1000];

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
	cin >> n;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			cin >> map[y][x];
		}
	}

	for (int y = 0; y < n; ++y) {
		for (int x = y + 1; x < n; ++x) {
			if (map[y][x] == 1) {
				if (Find(y) == Find(x) && Find(y) != 0) {
					cout << "WARNING";
					return 0;
				}
				else Union(y, x);
			}
		}
	}

	cout << "STABLE";
	return 0;
}