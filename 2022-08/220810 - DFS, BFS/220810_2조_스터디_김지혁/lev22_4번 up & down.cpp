#include <iostream>
using namespace std;

int man = 1;

void up()
{
	man++;

	return;
}

void down()
{
	man--;

	return;
}

void go(string str)
{
	if (str[0] == 'u') { up(); }
	else if (str[0] == 'd') { down(); }

	return;
}

int main()
{
	string command;

	for (int i = 0; i < 5; i++) {
		cin >> command;
		go(command);
	}

	if (man > 0) { cout << man; }
	else if (man <= 0) { cout << "B" << abs(man) + 1; }

	return 0;
}