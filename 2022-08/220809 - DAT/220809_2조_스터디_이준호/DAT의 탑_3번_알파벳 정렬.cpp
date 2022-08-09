#include <iostream>
using namespace std;

int main() {
	char alphabet[5][3] = {
	{'A', 'B', 'C'},
	{'A', 'G', 'H'},
	{'H', 'I', 'J'},
	{'K', 'A', 'B'},
	{'A', 'B', 'C'}
	};

	int dat[26] = { 0 };

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			dat[int(alphabet[i][j]) - 65]++;
		}
	}

	int t = 65;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < dat[i]; j++) {
			cout << char(t);
		}
		t++;
	}
	return 0;
}