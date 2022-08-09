#include <iostream>
#include <string>
using namespace std;
int main() {

	string Arr;
	cin >> Arr;
	int A[100] = { 0 };
	for (int i = 0; i < Arr.length(); i++) {
		A[Arr[i]] = 1;
	}
	for (int i = 0; i < 100; i++) {
		if (A[i] == 1) {
			cout << char(i);
		}
	}

	return 0;
}