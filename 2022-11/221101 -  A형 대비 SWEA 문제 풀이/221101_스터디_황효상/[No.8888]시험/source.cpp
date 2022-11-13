#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <stack>
#include <memory.h>
#include <algorithm>

using namespace std;


struct Node {
	int idx;
	int solved;
	int point;
};
int Tc;
int N,P,T;
int point[2001];
int info[2001][2001];
Node tmp[2001];
bool cmp(Node a, Node b) {
	if (a.point == b.point) {
		if (a.solved == b.solved) {
			return a.idx < b.idx;
		}
		return a.solved > b.solved;
	}
	return a.point > b.point;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);

	cin >> Tc;
	for (int t = 1; t <= Tc; ++t) {
		cin >> N >> T >> P;
		--P;
		for (int a = 0; a < N; ++a) {
			for (int b = 0; b < T; ++b) {
				cin >> info[a][b];
				if (info[a][b] == 0) {
					++point[b];
				}
			}
		}
		for (int a = 0; a < N; ++a) {
			int totalSum = 0;
			int solved = 0;
			for (int b = 0; b < T; ++b) {
				if (info[a][b] == 1) {
					++solved;
					totalSum = totalSum + point[b];
				}
			}
			tmp[a] = { a,solved,totalSum };
		}

		sort(tmp, tmp + N, cmp);
		for (int a = 0; a < N; ++a) {
			if (tmp[a].idx == P) {
				cout << "#" << t << " " << tmp[a].point << " " << a + 1 << "\n";
			}
		}
		memset(tmp, 0, sizeof(tmp));
		memset(point, 0, sizeof(point));
	}
	
	return 0;
}
