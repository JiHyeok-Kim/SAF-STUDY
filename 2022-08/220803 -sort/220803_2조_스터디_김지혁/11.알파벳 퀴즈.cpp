#include <iostream>
using namespace std;

int main()
{
	char arr[6] = { 'A','P','P','L','E','T' };

	char ch[5];
	for (int i = 0; i < 5; i++) {
		cin >> ch[i];
	}

	int cnt = 0;
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 6; x++) {
			if (arr[x] == ch[y]) { cnt++; }
		}
	}

	cout << cnt << "개 맞추었습니다";

	return 0;
}