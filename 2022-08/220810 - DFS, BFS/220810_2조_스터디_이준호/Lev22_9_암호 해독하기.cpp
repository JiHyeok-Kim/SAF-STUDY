#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<string> str = {
		"Jason",
		"Dr.tom",
		"EXEXI",
		"GK12P",
		"POW"
	};

	string input;
	cin >> input;

	int flag = 0;
	for (int i = 0; i < 5; i++) {
		if (input == str[i]) {
			flag = 1;
			break;
		}
	}

	if (flag == 1) cout << "��ȣ����";
	else cout << "��ȣƲ��";

	return 0;
}