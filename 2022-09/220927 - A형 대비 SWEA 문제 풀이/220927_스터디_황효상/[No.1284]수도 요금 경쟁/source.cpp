#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

long long P, Q, R, S, W;
void input() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> P >> Q >> R >> S >> W;

		long long A = W*P;
		long long B = Q;
		if (W > R) {
			A = A * W;
			B += ((W - R) * S);
		}
		cout << "#" << t << " " << min(A, B) << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	input();
	return 0;
}
