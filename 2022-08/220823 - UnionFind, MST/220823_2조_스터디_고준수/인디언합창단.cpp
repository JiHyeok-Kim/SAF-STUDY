#include <iostream>
using namespace std;

int n;
char line[30];
int groupCnt;
int perCnt;
int dat[200];

char findBoss(char tar) {
	if (line[tar] == 0) return tar;
	return line[tar] = findBoss(line[tar]);
}

void unionGroup(char a, char b) {
	char t1 = findBoss(a);
	char t2 = findBoss(b);
	if (t1 == t2) return;
	line[t2] = t1;
	groupCnt++;

	if (dat[a] == 0) perCnt++;
	if (dat[b] == 0) perCnt++;
	dat[a] = 1;
	dat[b] = 1;
}

int main() {

	//freopen_s(new FILE *, "input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b;
		cin >> a >> b;

		unionGroup(a, b);
	}

	cout << perCnt - groupCnt << '\n';
	cout << 26 - perCnt;

	return 0;
}