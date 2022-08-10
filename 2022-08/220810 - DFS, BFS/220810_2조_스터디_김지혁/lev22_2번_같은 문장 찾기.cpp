#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str11, str22, str33;
	cin >> str11 >> str22 >> str33;

	if (str11 == str22 && str11 == str33) { cout << "WOW"; }
	else if (str11 != str22 && str11 != str33) { cout << "BAD"; }
	else { cout << "GOOD"; }

	return 0;
}