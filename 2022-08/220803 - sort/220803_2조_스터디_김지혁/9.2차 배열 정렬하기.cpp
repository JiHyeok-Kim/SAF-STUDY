#include <iostream>
using namespace std;

int main()
{
	int arr2[2][3];
	int arr1[6];

	int i = 0;
	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < 3; x++) {
			cin >> arr2[y][x];
			arr1[i] = arr2[y][x];
			i++;
		}
	}

	int temp;
	for (int y = 0; y < 6; y++) {
		for (int x = y + 1; x < 6; x++) {
			if (arr1[y] > arr1[x]) { temp = arr1[y]; arr1[y] = arr1[x]; arr1[x] = temp; }
		}
	}

	int j = 0;
	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < 3; x++) {
			arr2[y][x] = arr1[j];
			j++;
		}
	}

	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < 3; x++) {
			cout << arr2[y][x] << " ";
		}
		cout << "\n";
	}

	return 0;
}