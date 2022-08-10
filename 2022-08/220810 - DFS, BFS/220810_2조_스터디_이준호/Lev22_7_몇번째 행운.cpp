#include <iostream>
#include <cstring>
using namespace std;

char arr[10];
char path[10];
int cnt = 0;

void run(int lev) {


	if (lev == 3) {
		cnt++;
		if (strcmp(arr, path) == 0) {
			cout << cnt << "¹øÂ°";
			return;
		}
		else return;
	}

	for (int i = 0; i < 4; i++) {
		path[lev] = 'A' + i;

		run(lev + 1);

		path[lev] = 0;
	}

}

int main() {
	cin >> arr;

	run(0);

}