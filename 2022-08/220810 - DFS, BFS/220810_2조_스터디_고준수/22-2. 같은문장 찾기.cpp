#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char va[10], vb[10], vc[10];
	cin >> va >> vb >> vc;

	int a = strcmp(va, vb);
	int b = strcmp(va, vc);
	int c = strcmp(vb, vc);

	if (a == 0 && b == 0)
	{
		cout << "WOW";
	}
	else if (a != 0 && b != 0 && c != 0)
	{
		cout << "BAD";
	}
	else
	{
		cout << "GOOD";
	}

	return 0;
}