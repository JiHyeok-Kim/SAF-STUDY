#include <iostream>
using namespace std;

int main()
{
	int arr[4][4];
	int n;
	cin >> n;

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (y % 2 == 0) { arr[y][x] = n; }
			else { arr[y][3 - x] = n; }
			n++;
		}
	}

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cout << arr[y][x] << " ";
		}
		cout << "\n";
	}

	return 0;
}