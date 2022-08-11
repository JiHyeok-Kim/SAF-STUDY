#include <iostream>
#include <string>

using namespace std;

int main()
{
	string pw[5] = {"Jason","Dr.tom","EXEXI","GK12P","POW" };
	
	string s;
	int flag = 0;
	cin >> s;
	for (int a = 0; a < 5; a++)
	{
		if (s == pw[a])
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
	{
		cout << "암호해제";
	}
	else
	{
		cout << "암호틀림";
	}

	return 0;
}