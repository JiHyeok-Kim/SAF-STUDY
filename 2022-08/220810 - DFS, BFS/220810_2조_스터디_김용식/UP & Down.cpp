#include <iostream>
#include <string>
using namespace std;
int main() {
	int x = 1;
	string up = "2";
	string down = "B1";

	string app;
	for (int i = 0; i < 5; i++) {
		cin >> app;
		if (app == "up") {
			x += 1;
		}
		else if (app == "down") {
			x -= 1;
		}
	}

	if (x > 0) {
		cout << x;
	}
	else if (x < 0) {
		cout << "B" << abs(x-1);
	}


	return 0;
}