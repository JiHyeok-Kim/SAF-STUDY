#include <iostream>
using namespace std;

char path[3];
char name[5];
int used[4];

void run(int lev)
{
	if (lev == 3) {
		cout << path << "\n";
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		path[lev] = name[i];
		run(lev + 1);
		path[lev] = 0;
		used[i] = 0;
	}

	return;
}

int main()
{
	cin >> name;
	run(0);

	return 0;
}