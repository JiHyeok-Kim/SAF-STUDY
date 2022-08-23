#include <iostream>
#include <string>
using namespace std;

int N, T;
int parent[130];
int cntPol[130], cntCon[130];

int Find(int now) {
	if (parent[now] == now) return now;
	return parent[now] = Find(parent[now]);
}

void Union(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);
	if (pA == pB) return;
	parent[pB] = pA;
	cntPol[pA] += cntPol[pB];
	cntCon[pA] += cntCon[pB];
	cntPol[pB] = 0;
	cntCon[pB] = 0;
}

void war(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);
	if (cntPol[pA] > cntPol[pB]) cntPol[pB] = 0;
	else cntPol[pA] = 0;
}

int main() {
	cin >> N;
	for (int i = 'A'; i < 'A' + N; i++) {
		int temp;
		cin >> temp;
		parent[i] = i;
		cntPol[i] = temp;
		cntCon[i] = 1;
	}
	cin >> T;
	for (int i = 0; i < T; i++) {
		string cmd;
		char a, b;
		cin >> cmd >> a >> b;
		if (cmd == "alliance") Union(a, b);
		if (cmd == "war") war(a, b);
	}
	int ans = 0;
	for (int i = 'A'; i < 'A' + N; i++) {
		if (cntPol[i] > 0) ans += cntCon[i];
	}
	cout << ans;
	return 0;
}