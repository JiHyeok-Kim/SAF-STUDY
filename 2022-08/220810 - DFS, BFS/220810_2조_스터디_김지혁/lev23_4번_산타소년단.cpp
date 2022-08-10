#include <iostream>
using namespace std;

int n;
char path[5];
char name[5] = { 'B','T','S','K','R' };
int used[5];
int cnt;

void run(int lev)
{
	if (lev == n) {
		int flag = 0;
		for (int i = 0; i < n; i++) {
			if (path[i] == 'S') { flag = 1; }
		}
		if (flag == 0) { return; }
		cnt++;
		return;
	}

	for (int i = 0; i < 5; i++) {
		if (used[i] == 1) { continue; }
		used[i] = 1;
		path[lev] = name[i];
		run(lev + 1);
		used[i] = 0;
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