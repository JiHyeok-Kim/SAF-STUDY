#include <iostream>
#include <string.h>
using namespace std;

int T, tc;
int DAT[101];

int Solve() {
	memset(DAT, 0, sizeof(DAT));
	for (int i = 0; i < 1000; ++i) {
		int score;
		cin >> score;
		DAT[score]++;
	}

	int maxi = -1;
	int maxi_ret = -1;
	for (int i = 100; i >= 0; --i) {
		if (maxi < DAT[i]) {
			maxi = DAT[i];
			maxi_ret = i;
		}
	}

	return maxi_ret;
}

int main()
{
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> tc;
		int ret = Solve();
		cout << "#" << tc << " " << ret << "\n";
	}
	return 0;
}