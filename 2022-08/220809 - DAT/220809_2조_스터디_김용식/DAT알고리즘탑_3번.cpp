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

	int arr[26] = { 0 };
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			arr[alphabet[i][j] - 'A']++;
		}
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < arr[i]; j++) {
			cout << (char)(i + 'A');
		}
	}


	return 0;
}