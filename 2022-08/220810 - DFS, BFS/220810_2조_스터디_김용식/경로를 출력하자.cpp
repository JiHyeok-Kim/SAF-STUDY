#include <iostream>
using namespace std;

char path[10];

void run(int lev) {
	if (lev == 2) {
		cout << path << endl;
		return;
	}
	for (int i = 0; i < 3; i++) {

		/*if (lev == 0 && i == 2)continue;
		if (lev == 0 && i == 3)continue;*/

		path[lev] = 'A' + i;
		run(lev + 1);
		path[lev] = 0;
	}

}

int main() {
	run(0);
	return 0;
}