#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int A, B, ans;
string D, tar;
int dat[1000001];

bool isSosu(int num) {
	int last = sqrt(num);
	for (int i = 2; i <= last; i++) {
		if (num % i == 0) return 0;
	}
	return 1;
}
void makeTong() {
	for (int i = 2; i <= 1000000; i++) {
		if (isSosu(i)) {
			dat[i]++;
		}
	}

}

void solve() {

	for (int k = A; k <= B; k++) {
		if (dat[k] == 1) {
			tar = to_string(k);
			if (tar.find(D) != -1)
			{
				ans++;
			}
		}
	}
}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	makeTong();
	for (int tc = 1; tc <= tcCnt; tc++) {
		ans = 0;
		cin >> D >> A >> B;
		solve();
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}