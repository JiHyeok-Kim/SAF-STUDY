#include <iostream>
#include <cstring>
using namespace std;



int main() {

	char arr1[10], arr2[10], arr3[10];
	cin >> arr1 >> arr2 >> arr3;

	if (strcmp(arr1, arr2) == 0 && strcmp(arr1, arr3) == 0) {
		cout << "WOW";
	}
	else if (strcmp(arr1, arr2) != 0 && strcmp(arr1, arr3) != 0 && strcmp(arr2, arr3) != 0) {
		cout << "BAD";
	}
	else cout << "GOOD";



	return 0;
}