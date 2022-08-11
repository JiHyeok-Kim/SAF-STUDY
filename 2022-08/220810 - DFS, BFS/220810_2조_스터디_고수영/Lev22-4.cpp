#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s[5] = {};
	int n = 1;
	for (int a = 0; a < 5; a++)
	{
		cin >> s[a];
		if (s[a] == "up")
		{
			n++;
		}
		else
		{
			n--;
		}
	}
	if (n <= 0)
	{
		cout << "B" << (-(n - 1));
	}
	else
	{
		cout << n;
	}

	return 0;
}