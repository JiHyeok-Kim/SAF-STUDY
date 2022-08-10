#include <iostream>
using namespace std;

int n;
char path[10];
int count12 = 0;

void run(int lev) {
	if (lev == n) {
		count12++;

		//cout << path << " "<<endl;
		return;
	}
	for (int i = 0; i < 3; i++) {
		path[lev] = 'A' + i;
		if (lev >= 2 && (path[lev] == path[lev - 1]) && (path[lev ] == path[lev - 2]))continue;
		run(lev + 1);
		path[lev] = 0;
	}

}

int main() {
	
	cin >> n;
	run(0);
	cout << count12;
	return 0;
}