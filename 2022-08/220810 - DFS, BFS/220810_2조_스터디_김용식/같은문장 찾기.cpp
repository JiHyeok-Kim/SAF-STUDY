#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char arr[10];
	char arr2[10];
	char arr3[10];

	cin >> arr >> arr2 >> arr3;
	if (strcmp(arr, arr2) == 0 && strcmp(arr, arr3) == 0) {
		cout << "WOW";
	}
	else if (strcmp(arr, arr2) == 0 || strcmp(arr, arr3) == 0) {
		cout << "GOOD";
	}
	else if (!(strcmp(arr, arr2) == 0 && strcmp(arr, arr3) == 0)) {
		cout << "BAD";
	}

}