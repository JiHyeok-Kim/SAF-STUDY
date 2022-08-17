#include <iostream>
using namespace std;

int main() {
	int money = 0;
	cin >> money;

	int coin = 0;

	coin += money / 500;
	money = money % 500;
	coin += money / 100;
	money = money % 100;
	coin += money / 50;
	money = money % 50;
	coin += money / 10;
	
	cout << coin;

	return 0;
}