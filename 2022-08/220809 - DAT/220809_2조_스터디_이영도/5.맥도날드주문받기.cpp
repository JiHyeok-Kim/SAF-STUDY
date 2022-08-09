#include<iostream>

using namespace std;
struct MC {
	char burger1[8];
	char burger2[8];
};

int getLength(char burger[8])
{
	for (int x = 0; x < 8; x++)
	{
		if (burger[x] == '\0')
		{
			return x;
		}
	}
}

int main() {
	MC bob, tom;
	cin >> bob.burger1;
	cin >> bob.burger2;
	cin >> tom.burger1;
	cin >> tom.burger2;

	cout << "bob.burger1=" << getLength(bob.burger1) << endl;
	cout << "bob.burger2=" << getLength(bob.burger2) << endl;
	cout << "tom.burger1=" << getLength(tom.burger1) << endl;
	cout << "tom.burger2=" << getLength(tom.burger2) << endl;

	return 0;
}