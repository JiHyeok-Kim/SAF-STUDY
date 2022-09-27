#include <iostream>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		int dat[1001] = { 0 };

		for (int i = 0; i < 1000; i++) {
			int score;
			cin >> score;
			dat[score]++;
		}

		int maxVal = 0;
		int answer = 0;

		for (int i = 1; i <= 1000; i++) {
			if (dat[i] >= maxVal) {
				maxVal = dat[i];
				answer = i;
			}
		}

		cout << "#" << t << " " << answer << '\n';
	}
	return 0;
}