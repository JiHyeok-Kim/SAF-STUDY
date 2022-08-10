#include <iostream>
using namespace std;

char name[6] = "BTSKR";
char path[10];
int used[10];
int cnt = 0;
int n;

void run(int lev) {
	int flag = 0;

	if (lev == n) {
		for (int k = 0; k < n; k++) {
			if (path[k] == 'S') {
				flag = 1;
				break;
			}
		}
		if (flag == 0) return;
		cnt++;
		return;
	}

	for (int i = 0; i < 5; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		path[lev] = name[i];
		run(lev + 1);
		path[lev] = 0;
		used[i] = 0;

	}

}

int main() {
	cin >> n;

	run(0);

	cout << cnt;

	return 0;
}