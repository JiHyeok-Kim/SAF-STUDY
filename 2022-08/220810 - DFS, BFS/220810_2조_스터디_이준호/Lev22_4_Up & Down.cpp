#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int t = 0;
	char arr[5];

	for (int i = 0; i < 5; i++) {
		cin >> arr;

		int up = strcmp(arr, "up");
		int down = strcmp(arr, "down");

		if (up == 0) {
			t++;
		}
		else if (down == 0) {
			t--;
		}
	}

	if (t > 0) {
		cout << t + 1;
	}
	else cout << "B" << -t;

	return 0;
}