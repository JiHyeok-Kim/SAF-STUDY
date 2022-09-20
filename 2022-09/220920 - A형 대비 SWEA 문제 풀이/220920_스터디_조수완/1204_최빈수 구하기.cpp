#include <iostream>
using namespace std;

int dat[110], tc;

void init() {
	for (int i = 0; i < 101; i++) {
		dat[i] = 0;
	}
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> tc;
		init();
		for (int i = 0; i < 1000; i++) {
			int temp;
			cin >> temp;
			dat[temp]++;
		}
		int maxi = -1;
		int maxidx = 0;
		for (int i = 0; i < 101; i++) {
			if (maxi <= dat[i]) {
				maxi = dat[i];
				maxidx = i;
			}
		}
		cout << "#" << tc << " " << maxidx << "\n";
	}

	return 0;
}