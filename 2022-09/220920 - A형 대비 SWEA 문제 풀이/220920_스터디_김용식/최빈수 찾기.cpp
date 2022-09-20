#include <iostream>
using namespace std;
int dat[101] = { 0 };


int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++){
		int a;
		cin >> a;
		for (int i = 0; i < 1000; i++) {
			int score;
			cin >> score;
			dat[score]++;
		}
		int Max = -2134567890;
		int Maxidx = 0;
		for (int i = 0; i <= 100; i++) {
			if (dat[i] >= Max) {
				Max = dat[i];
				Maxidx = i;
			}
			dat[i] = 0;
		}
		cout << "#" << i << " " << Maxidx << '\n';
	}

	return 0;
}