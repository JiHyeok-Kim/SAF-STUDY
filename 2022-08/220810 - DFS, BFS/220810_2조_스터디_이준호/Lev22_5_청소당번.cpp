#include <iostream>
#include <cstring>
using namespace std;

int bran;
int path[10];

void run(int lev)
{

	if (lev == 4) {
		for (int i = 0; i < 4; i++) {
			cout << path[i] + 1;
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < bran; i++) {
		path[lev] = i;
		run(lev + 1);
		path[lev] = 0;

	}
}



int main() {
	cin >> bran;

	run(0);

	return 0;
}