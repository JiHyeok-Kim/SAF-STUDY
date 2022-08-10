#include <iostream>
using namespace std;

int main()
{
	string arr[5] = { "Jason", "Dr.tom", "EXEXI", "GK12P", "POW" };
	string str;
	cin >> str;

	int flag = 0;
	for (int i = 0; i < 5; i++) {
		if (arr[i] == str) { flag = 1; }
	}

	if (flag == 1) { cout << "암호해제"; }
	else if (flag == 0) { cout << "암호틀림"; }

	return 0;
}