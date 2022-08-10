#include <iostream>
using namespace std;

int n;
int cnt = 0;
char path[3] = { 'O','O','O' };
char name[3] = { 'A','B','C' };

void run(int lev)
{
	if (lev == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < 3; i++) {
		path[lev] = name[i];
		if (lev >= 2 && path[lev - 2] == path[lev - 1] && path[lev] == path[lev - 1]) continue;
		run(lev + 1);
	}

	return;
}

int main()
{
	cin >> n;
	run(0);
	cout << cnt;

	return 0;
}