#include <iostream>
using namespace std;

int T, N;
int parent[100001];

void init() {
	for (int i = 0; i <= T; ++i) {
		parent[i] = i;
	}
}

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
}

int main()
{
	cin >> T >> N;
	init();
	int ret = 0;
	while (N--) {
		int car;
		cin >> car;
		int target = Find(car);
		if (target == 0) break;
		Union(target - 1, target);
		ret++;
	}

	cout << ret;
	return 0;
}