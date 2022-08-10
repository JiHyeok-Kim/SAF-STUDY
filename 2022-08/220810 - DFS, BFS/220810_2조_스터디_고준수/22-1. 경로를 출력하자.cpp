#include<iostream>
using namespace std;
char path[10];
void recur(int level) {
	if (level == 2) {
		cout << path << endl;
		return;
	}
	for (int x = 0; x < 3; x++) {
		path[level] = 'A' + x;
		recur(level + 1);
		path[level] = 0;
	}
}
int main() {
	recur(0);
	return 0;
}