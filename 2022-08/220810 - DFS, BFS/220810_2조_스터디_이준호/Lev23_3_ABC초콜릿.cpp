#include <iostream>
using namespace std;

char name[4] = "ABC";
char path[10];
int used[10];
int cnt = 0;
int lim;

void run(int lev) {

	if (lev >= 3 && path[lev - 1] == path[lev - 2] &&
		path[lev - 1] == path[lev - 3])
	{
		return;
	}

	if (lev == lim) {
		cnt++;
		return;
	}

	for (int i = 0; i < 3; i++) {

		path[lev] = name[i];
		run(lev + 1);
		path[lev] = 0;

	}

}

int main() {
	cin >> lim;

	run(0);

	cout << cnt;

	return 0;
}