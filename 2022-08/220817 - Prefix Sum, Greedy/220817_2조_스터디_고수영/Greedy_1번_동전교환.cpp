#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int coin[4] = { 500,100,50,10 };

int main() 
{
	int cnt = 0;
	int money;
	cin >> money;

	for (int i = 0; i < 4; i++)
	{
		cnt += money / coin[i];
		money = money % coin[i];
	}
	cout << cnt;
}