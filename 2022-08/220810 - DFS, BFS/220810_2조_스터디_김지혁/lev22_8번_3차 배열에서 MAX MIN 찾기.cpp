#include <iostream>
using namespace std;

int main()
{
	int arr[3][2][2] = { {{2,4}, {1,5}}, { {2,3}, {3,6}}, { {7,3}, {1,5}} };

	int n;
	cin >> n;

	int max = -999;
	int min = 999;
	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < 2; x++) {
			if (arr[n][y][x] > max) { max = arr[n][y][x]; }
			if (arr[n][y][x] < min) { min = arr[n][y][x]; }
		}
	}
	cout << "MAX=" << max << "\n";
	cout << "MIN=" << min;

	return 0;
}