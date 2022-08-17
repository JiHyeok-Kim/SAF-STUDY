#include <iostream>
using namespace std;

int main()
{
	int coin[4] = { 500,100,50,10 };
	int target;
	cin >> target;

	int ret = 0;
	for (int i = 0; i < 4; ++i) {
		ret += target / coin[i];
		target %= coin[i];
	}

	cout << ret;
	return 0;
}