#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	char x[3][11] = {};
	for (int a = 0; a < 3; a++)
	{
		cin >> x[a];
	}

	char tmp[11] = {};

	if ((!strcmp(x[1], x[2]) && !strcmp(x[1], x[0])))
	{
		cout << "WOW";
	}
	else if ((strcmp(x[1], x[2]) && strcmp(x[1], x[0])))
	{
		cout << "BAD";
	}
	else
	{
		cout << "GOOD";
	}
}