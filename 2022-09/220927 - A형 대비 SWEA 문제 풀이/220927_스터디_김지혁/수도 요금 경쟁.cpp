#include <iostream>
using namespace std;

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int P, Q, R, S, W;
		cin >> P >> Q >> R >> S >> W;

		int ans = 0;
		if (W <= R) ans = Q;
		else{
			ans = Q + (W - R) * S;
		}

		if (ans > W * P) {
			ans = W * P;
		}

		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}