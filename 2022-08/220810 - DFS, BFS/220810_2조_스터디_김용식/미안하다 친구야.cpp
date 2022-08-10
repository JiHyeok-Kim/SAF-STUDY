#include <iostream>
using namespace std;

char path[10];
char name[5] = { 'E','W','A','B','C' };
char arr;
int used[10];
void run(int lev) {
	//if (path[0] == arr || path[1] == arr || path[2] == arr || path[3] == arr || path[4] || arr) return;
	if (path[0] == arr||path[1]==arr||path[2]==arr||path[3]==arr)return;
	if (lev == 4) {
		cout << path << "\n";
		return;
	}
	for (int i = 0; i < 5; i++) {
		if (used[i] == 1)continue;
		used[i] = 1;
		path[lev] = name[i];
		run(lev + 1);
		path[lev] = 0;
		used[i] = 0;
	}
}


int main() {
	cin >> arr;
	run(0);
	return 0;
}