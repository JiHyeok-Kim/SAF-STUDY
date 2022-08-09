#include<iostream>
using namespace std;

struct Train
{
	int win;
	char name[8];
};

int isSame(char name[8], char lover[8]) {
	int n1, n2;
	for (int x = 0; x < 8; x++) {
		if (name[x] == '\0') {
			n1 = x;
			break;
		}
	}
	for (int x = 0; x < 8; x++) {
		if (lover[x] == '\0') {
			n2 = x;
			break;
		}
	}
	if (n1 != n2) return 0;

	for (int x = 0; x < n1; x++)
	{
		if (name[x] != lover[x]) return 0;
	}
	return 1;
}

int main()
{
	Train t[7] = { {15, "summer"}, {33, "cloe"}, {24, "summer"}, {28, "niki"}, {32, "jenny"}, {20, "summer"}, {40, "coco"} };

	char lover[8] = { 0 };
	int age;

	cin >> lover;
	cin >> age;

	int x;

	for (x = 0; x < 7; x++)
	{
		if (t[x].win == age && isSame(t[x].name, lover) == 1)
		{
			cout << x;
			break;
		}
	}

	return 0;
}