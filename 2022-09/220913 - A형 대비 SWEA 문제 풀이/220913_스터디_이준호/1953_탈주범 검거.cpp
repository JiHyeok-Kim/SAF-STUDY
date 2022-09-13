#include <iostream>
using namespace std;

int N;
int map[16][16];


int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		cin >> N;
		
		memset(map, 0, sizeof(map))
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				cin >> map[y][x];
			}
		}

		for (int y = 0; y < N - 1; y++) {
			for (int x = y + 1; x < N; x++) {
				cout << map[y][x] << " ";
			}
			cout << "\n";
		}

	}
	return 0;
}