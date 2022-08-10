#include <iostream>
#include <string>
using namespace std;
string a;

char path[10];

int used[10] = { 0 };

int cnt = 0;

int flag = 0;

void run(int lev) {
	if (lev == 4) {
		flag = 0;
		for (int i = 1; i < 4; i++) {
			if (abs(path[i] - path[i - 1]) > 3) {
				flag = 1;
			}
		}
		if (flag == 0) {
			cnt++;
		}

		return;
	}

	for (int i = 0; i < 5; i++) {
		path[lev] = a[i];
		run(lev + 1);
		path[lev] = 0; 
	}
}

int main() {
	cin >> a;
	run(0);
	
	cout << cnt;
	return 0;
}