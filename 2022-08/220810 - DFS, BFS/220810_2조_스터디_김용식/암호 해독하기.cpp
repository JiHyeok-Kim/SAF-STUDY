#include <iostream>
#include <string>
using namespace std;
int main() {

	string str[5] = {
	"Jason",
	"Dr.tom",
	"EXEXI",
	"GK12P",
	"POW"
	};
	string arr;
	cin >> arr;
	int flag = 0;
	for (int i = 0; i < 5; i++) {
		if (str[i] == arr) {
			flag = 1;
		}
	}

	if (flag == 1) {
		cout << "암호해제";
	}
	else
		cout << "암호틀림";
	return 0;
}