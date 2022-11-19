#include <iostream>
#include <string>
using namespace std;

string str1, str2;
int now[3];
int last[3];
int hour, minute, sec;

void solve() {

	for (int i = 0; i < 3; i++) {
		now[i] = stoi(str1.substr(i * 3, 2));
		last[i] = stoi(str2.substr(i * 3, 2));
	}

	sec = last[2] - now[2];
	minute = last[1] - now[1];
	hour = last[0] - now[0];
	
	if (sec < 0) {
		sec += 60;
		minute -= 1;
	}
	if (minute < 0) {
		minute += 60;
		hour -= 1;
	}
	if (hour < 0) {
		hour += 24;
	}
}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		cin >> str1 >> str2;
		solve();
		cout << "#" << tc << " ";
		printf("%02d:%02d:%02d", hour, minute, sec);
		cout << "\n";
	}

	return 0;
}