#include <iostream>
using namespace std;
char path[10];
char name[4];
int used[10];
void run(int lev) {
	if (lev == 3) {
		cout << path << "\n";
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (used[i] == 1)continue;
		path[lev] = name[i];
		used[i] = 1;
		run(lev + 1);
		path[lev] = 0;
		used[i] = 0;
	}
}


int main() {
	cin >> name;
	run(0);
	return 0;
}