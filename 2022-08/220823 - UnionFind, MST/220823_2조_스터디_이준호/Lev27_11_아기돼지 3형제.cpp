#include <iostream>
#include <string>
using namespace std;

char arr[4][4];

int main() {
	int a, b;
	for (int i = 0; i < 3; i++) {
		cin >> a >> b;
		arr[a][b] = '#';
	}

	int ditY[8] = { -1,-1,-1,0,0,1,1,1 };
	int ditX[8] = { -1,0,1,-1,1,-1,0,1 };

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (arr[y][x] == '#') {
				for (int i = 0; i < 8; i++) {
					int ny = y + ditY[i];
					int nx = x + ditX[i];
					if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) continue;
					arr[ny][nx] = '@';
				}

			}
		}
	}

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (arr[y][x] == 0) cout << '_';
			else cout << arr[y][x];
		}
		cout << "\n";
	}

	return 0;
}