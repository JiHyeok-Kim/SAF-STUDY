#include <iostream>
using namespace std;

int parent[130], cntMem[130], N;

int Find(int now) {
	if (parent[now] == now) return now;
	return parent[now] = Find(parent[now]);
}

void Union(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);
	if (pA == pB) return;
	parent[pB] = pA;
	cntMem[pA] += cntMem[pB];
	cntMem[pB] = 0;
}

int main() {
	for (int i = 'A'; i <= 'Z'; i++) {
		parent[i] = i;
		cntMem[i] = 1;
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		char a, b;
		cin >> a >> b;
		Union(a, b);
	}
	int cntTeam = 0, cntUnTeam = 0;
	for (int i = 'A'; i <= 'Z'; i++) {
		if (cntMem[i] > 1) cntTeam++;
		if (cntMem[i] == 1) cntUnTeam++;
	}
	cout << cntTeam << '\n' << cntUnTeam;
	return 0;
}