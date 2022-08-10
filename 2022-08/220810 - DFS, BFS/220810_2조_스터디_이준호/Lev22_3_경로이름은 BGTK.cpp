#include <iostream>
#include <cstring>
using namespace std;

int a;
char path[10];
char arr[5] = "BGTK";

void run(int lev) {

	if (lev == a) {
		cout << path << "\n";
		return;
	}

	for (int i = 0; i < 4; i++) {
		path[lev] = arr[i];
		run(lev + 1);
		path[lev] = 0;
	}

}


int main() {


	cin >> a;
	run(0);

	return 0;
}