#include<iostream>
#include<cstring>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

string st;
int used[4];
char path[10];

void run(int lev) {
	if (lev == 3) {
		cout << path << endl;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		path[lev] = st[i];
		run(lev + 1);
		path[lev] = 0;
		used[i] = 0;
	}
}

int main() {
	cin >> st;
	run(0);

	return 0;
}
