#include <iostream>
using namespace std;

int P, Q, R, S, W;

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int tc;
	cin >> tc;

	for (int TC = 1; TC <= tc; TC++) {
		cin >> P >> Q >> R >> S >> W;
		int SumA = 0;
		int SumB = 0;

		SumA = P * W;
		if (W < R) SumB = Q;
		else {
			SumB = Q + ((W - R) * S);
		}
		cout << "#" << TC << " " << min(SumA, SumB) << '\n';
	}
	return 0;
}