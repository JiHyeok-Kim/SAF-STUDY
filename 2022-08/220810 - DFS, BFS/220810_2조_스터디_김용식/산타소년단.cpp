#include <iostream>
using namespace std;

int n;
char member[6] = { "BTSKR" };
char path[10];
int used[10] = { 0 };
int cnt=0;
int via[10] = { 0 };
void run(int lev) {
	if (lev == n) {
		for (int i = 0; i < n; i++) {
			if (path[i] == 'S') {
				
				cnt++;
				continue;
			}
		}
		return;
	}
	for (int i = 0; i < 5; i++) {
		if (via[i] == 0) {
			if (used[lev] == 1)continue;
			via[i] = 1;
			path[lev] = member[i];
			used[lev] = 1;
			run(lev + 1);
			via[i] = 0;
			used[lev] = 0;
			path[lev] = 0;
		}
	}	
}


int main() {	
	cin >> n;
	run(0);
	cout << cnt;
	return 0;
}