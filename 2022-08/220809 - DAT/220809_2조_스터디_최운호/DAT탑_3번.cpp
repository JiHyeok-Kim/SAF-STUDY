#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	char alphabet[5][3] = {
	{'A', 'B', 'C'},
	{'A', 'G', 'H'},
	{'H', 'I', 'J'},
	{'K', 'A', 'B'},
	{'A', 'B', 'C'}
	};

	int dat[200] = { 0 };

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			dat[alphabet[i][j]]++;
		}
	}

	for (int i = 0; i < 200; i++) {
		if (dat[i] == 0) continue;
		int n = dat[i];
		for (int j = 0; j < n; j++) {
			cout << (char)i;
		}
	}

	return 0;
}