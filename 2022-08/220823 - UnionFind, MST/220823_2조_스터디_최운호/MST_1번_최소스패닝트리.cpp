#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct EDGE {
	int from;
	int to;
	int val;
};

bool cmp(EDGE A, EDGE B) {
	if (A.val < B.val) return true;
	if (A.val > B.val) return false;

	return false;
}

EDGE arr[100000];

int v, e;
int parents[10000];


int Find(int now) {
	if (parents[now] == 0) return now;
	int ret = Find(parents[now]);
	parents[now] = ret;
	return ret;
}

void UNION(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);

	if (pA == pB) return;

	parents[pB] = pA;
}

int main() {
	cin >> v >> e;

	int result = 0;
	int cnt = 0;

	for (int i = 0; i < e; i++) {
		int from, to, val;
		cin >> from >> to >> val;
		arr[i] = { from,to,val };
	}

	sort(arr, arr+e, cmp);

	for (int i = 0; i < e; i++) {
		if (Find(arr[i].from) == Find(arr[i].to)) continue;

		UNION(arr[i].from, arr[i].to);
		cnt++;

		result += arr[i].val;
		if (cnt == v - 1) break;
	}

	cout << result;

	return 0;
}
