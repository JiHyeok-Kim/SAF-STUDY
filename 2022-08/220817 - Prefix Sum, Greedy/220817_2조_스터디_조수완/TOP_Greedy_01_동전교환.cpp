#include <iostream>
using namespace std;

int cost[4] = { 500,100,50,10 };
int money, cnt;

int main() {
	cin >> money;
	for (int i = 0; i < 4; i++) {
		cnt += money / cost[i];
		money %= cost[i];
	}
	cout << cnt;
	return 0;
}