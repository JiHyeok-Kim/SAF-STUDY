#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
	string str;
	string name;
	cin >> str;
	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> name;
		if (name.find(str, 0) != -1)
		{
			cout << "O" << '\n';
		}
		else if (name.find(str, 0) == -1)
		{
			cout << "X" << '\n';
		}
	}
}