#include <iostream>
#include <algorithm>
using namespace std;


int Arr[100000] = { 0 };

void clear() {
	for (int i = 0; i < 100000; i++) {
		Arr[i] = 0;
	}
	return;
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	
	int TC;
	cin >> TC;

	for (int tc = 1; tc <= TC; tc++) {
		int N;
		cin >> N;
		int Min = 21e8;
		for (int i = 0; i < N; i++) {
			int Doll;
			cin >> Doll;
			if (abs(Doll) < Min) {
				Min = abs(Doll);
				Arr[Min]++;
			}
			else {
				Arr[abs(Doll)]++;
			}
			
		}
		cout << "#" << tc << " " << Min << " " << Arr[Min] << '\n';
		clear();
	}

	return 0;
}