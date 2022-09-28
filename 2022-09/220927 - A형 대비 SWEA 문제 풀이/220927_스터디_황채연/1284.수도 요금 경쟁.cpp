#include <iostream>
using namespace std;

int T;
int P, Q, R, S, W;

int Solve() {
	if (P * W < Q) return P * W;
	int Acos = P * W;
	int Bcos = 0;
	if (W <= R) Bcos = Q;
	else Bcos = Q + S * (W - R);
	if (Acos < Bcos) return Acos;
	else return Bcos;
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> P >> Q >> R >> S >> W;
		int ret = Solve();
		cout << "#" << tc << " " << ret << "\n";
	}
	return 0;
}