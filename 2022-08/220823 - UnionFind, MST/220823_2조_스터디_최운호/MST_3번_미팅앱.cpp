#include <iostream>
#include <algorithm>
using namespace std;

struct edge {
	int a;
	int b;
	int val;
};

bool cmp(edge A, edge B) {
	if (A.val > B.val) return false;
	if (A.val < B.val) return true;

	return false;
}

int n, m;

edge arr[10000];

char info[1001];
int vect[1001];

int Find(int now) {
	if (vect[now] == 0) return now;
	int ret = Find(vect[now]);
	vect[now] = ret;
	return ret;
}
void UNION(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);

	if (pA == pB) return;

	vect[pB] = pA;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> info[i];
	}

	for (int i = 0; i < m; i++) {
		int from, to, val;
		cin >> from >> to >> val;
		arr[i] = { from, to, val };
	}

	sort(arr, arr + m, cmp);

	int cnt = 0;
	int result = 0;
	int ret = 0;

	for (int i = 0; i < m; i++) {
		if (info[arr[i].a] == info[arr[i].b]) continue;
		if (Find(arr[i].a) == Find(arr[i].b)) continue;

		UNION(arr[i].a, arr[i].b);
		cnt++;
		result += arr[i].val;
		if (cnt == n - 1) {
			ret = 1;
			break;
		}
	}
	if (ret) cout << result;
	else cout << "-1";
	return 0;
}