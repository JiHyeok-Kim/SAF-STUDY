#include <iostream>
#include <string>
using namespace std;

int path[10];
char name[10];
int cnt = 0;

void run(int lev)
{
	if (lev == 4) {
		cnt++;
		return;
	}

	for (int i = 0; i < 5; i++) {
		path[lev] = name[i];
		if (lev >= 1 && abs(path[lev] - path[lev - 1]) > 3) continue;
		run(lev + 1);
		path[lev] = 0;
	}

	return;
}

int main()
{
	cin >> name;
	run(0);
	cout << cnt;

	return 0;
}