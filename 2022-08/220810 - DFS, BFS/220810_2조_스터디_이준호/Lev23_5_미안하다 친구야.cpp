#include <iostream>
using namespace std;

char name[6] = "EWABC";
char ch;
char path[10];
int used[10];


void run(int lev) {
	int flag = 0;

	if (lev == 4) {
		for (int k = 0; k < 4; k++) {
			if (path[k] == ch) return;
		}
		cout << path << endl;
		return;
	}


	for (int i = 0; i < 5; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		path[lev] = name[i];
		run(lev + 1);
		path[lev] = 0;
		used[i] = 0;

	}

}

int main() {
	cin >> ch;

	run(0);

	return 0;
}