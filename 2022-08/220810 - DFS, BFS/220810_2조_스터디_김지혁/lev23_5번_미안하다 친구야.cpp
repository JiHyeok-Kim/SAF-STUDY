#include <iostream>
using namespace std;

char ch;
char path[4] = { '0','0','0','0' };
char name[5] = { 'E','W','A','B','C' };
int used[5] = { 0 };

void run(int lev)
{
	if (lev == 4) {
		cout << path << "\n";
		return;
	}

	for (int i = 0; i < 5; i++) {
		if (name[i] == ch) continue;
		if (used[i] == 1) continue;
		used[i] = 1;
		path[lev] = name[i];
		run(lev + 1);
		used[i] = 0;
	}

	return;
}

int main()
{
	cin >> ch;
	run(0);

	return 0;
}