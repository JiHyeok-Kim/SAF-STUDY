#include <iostream>
using namespace std;

int main()
{
	int arr[3][4] = { {12,11,10,9},{8,7,6,5},{4,3,2,1} };

	int n;
	cin >> n;
	if (n == 1) { for (int x = 0; x < 4; x++) { arr[0][x] = 7; } }
	else if (n == 2) { for (int x = 0; x < 4; x++) { arr[1][x] = 7; } }
	else if (n == 3) { for (int x = 0; x < 4; x++) { arr[2][x] = 7; } }

	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 4; x++) {
			cout << arr[y][x] << " ";
		}
		cout << '\n';
	}

	return 0;
}