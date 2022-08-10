#include <iostream>
using namespace std;

char name[5];
char path[100];
int used[100];
int cnt = 0;

void run(int lev) {

	if (lev == 4) {
		cnt++;
		return;
	}

	for (int i = 0; i < 4; i++) {

		path[lev] = name[i];
		if ((path[lev - 1] == 'B' && path[lev] == 'T') ||
			(path[lev - 1] == 'T' && path[lev] == 'B')) {
			continue;
		}
		run(lev + 1);
		path[lev] = 0;

	}

}

int main() {
	cin >> name;

	run(0);
	cout << cnt;
	return 0;
}