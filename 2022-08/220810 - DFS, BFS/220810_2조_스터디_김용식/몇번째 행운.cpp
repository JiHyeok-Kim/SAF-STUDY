#include <iostream>
#include <string>
using namespace std;

char path[10];
string a;
int aa = 0;
void run(int lev) {
	if(lev ==3){
		aa++;
		if (path == a) {
			cout << aa<< "번째";
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		path[lev] = 'A' + i;
		run(lev + 1);
		path[lev] = 0;
	}
}


int main() {
	cin >> a;
	run(0);
	return 0;
}