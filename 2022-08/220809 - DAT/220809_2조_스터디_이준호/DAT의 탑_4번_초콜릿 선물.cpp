#include <iostream>
#include <string>
using namespace std;

string str;
int dat[100];

int main() {

	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		dat[str[i]]++;
	}
	
	for (int i = 'A'; i <= 'Z'; i++) {
		if (dat[i] > 0) {
			cout << (char)i;
		}	
	}

	return 0;
}
