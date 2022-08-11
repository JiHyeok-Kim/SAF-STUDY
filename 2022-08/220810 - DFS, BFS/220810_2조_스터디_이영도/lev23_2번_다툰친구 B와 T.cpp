#include<iostream>

using namespace std;

string st;
char path[4];
int cnt;

void run(int lev) {
	if (lev == 4) {
		cnt++;

		return;
	} 

	for (int i = 0; i < 4; i++) {
	
		path[lev] = st[i];
		if (lev > 0 && path[lev] == 'T' && path[lev - 1] == 'B') continue;
		if (lev > 0 && path[lev] == 'B' && path[lev - 1] == 'T') continue;
		run(lev + 1);
		path[lev] = '0';
	}
}

int main() {
	cin >> st;
	run(0);
	cout << cnt << endl;

	return 0;
}
