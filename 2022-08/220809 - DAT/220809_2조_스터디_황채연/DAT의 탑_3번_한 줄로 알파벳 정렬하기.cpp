#include <iostream>
using namespace std;

int main()
{
	int cnt[150] = { 0, };
	char alphabet[5][3] = {
	{'A', 'B', 'C'},
	{'A', 'G', 'H'},
	{'H', 'I', 'J'},
	{'K', 'A', 'B'},
	{'A', 'B', 'C'}
	};

	for (int y = 0; y < 5; ++y) {
		for (int x = 0; x < 3; ++x) {
			cnt[alphabet[y][x]]++;
		}
	}

	for (int i = 0; i < 150; ++i) {
		if (cnt[i] == 0) continue;
		int size = cnt[i];
		for (int j = 0; j < size; ++j) {
			cout << char(i);
		}
	}

	return 0;
}