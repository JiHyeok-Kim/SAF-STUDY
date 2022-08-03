#include <iostream>
using namespace std;

int main()
{
	int arr[9] = { 0 };
	int input[3][2];

	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 2; x++) {
			cin >> input[y][x];
		}
	}

	for (int y = 0; y < 3; y++) {
		for (int x = input[y][0]; x <= input[y][1]; x++) {
			arr[x]++;
		}
	}

	for (int x = 0; x < 9; x++) {
		cout << arr[x] << " ";
	}

	return 0;
}