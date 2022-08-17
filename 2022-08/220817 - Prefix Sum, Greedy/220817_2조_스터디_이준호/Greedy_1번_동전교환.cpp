#include <iostream>
using namespace std;

int main() {

	int dong[4] = { 500,100,50,10 };
	int change;
	cin >> change;
	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		cnt += change / dong[i];
		change %= dong[i];
	}

	cout << cnt;
	return 0;
}