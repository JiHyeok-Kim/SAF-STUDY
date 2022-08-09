#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	int dat[200] = { 0 };

	for (int i = 0; i < str.size(); i++) {
		dat[str[i]] = 1;
	}

	for (int i = 0; i < 200; i++) {
		if (dat[i] == 1) cout << (char)i;
	}

	return 0;
}