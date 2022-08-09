#include <iostream>
using namespace std;

int main()
{
	int juso[8] = { 402,401,302,301,202,201,102,101 };
	char name[8][5] = { "KIM","TEA","SOM","OPPO","TOM","GDK","JAME","MIN" };

	int n;
	cin >> n;

	int idx;
	for (int x = 0; x < 8; x++) {
		if (juso[x] == n) { idx = x; }
	}

	for (int x = 0; x < 5; x++) {
		if (name[idx][x] == '\0') { break; }
		cout << name[idx][x];
	}
}