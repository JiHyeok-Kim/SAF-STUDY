#include <iostream>
#include <cstring>
using namespace std;

string str;
int len, flag, maxi;
int num[2500], valid[2500];

void init()
{
	maxi = flag = 0;
	memset(num, 0, sizeof(num));
	memset(valid, 0, sizeof(valid));
	cin >> str;
	len = str.length();

	int cntc, cntk;
	cntc = cntk = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == 'c') {
			num[i] = 1;
			cntc++;
		}
		else if (str[i] == 'k') {
			num[i] = -1;
			cntk++;
		}
	}
	if (cntc != cntk) flag = 1;
	if (flag == 1) return;

	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += num[i];
		maxi = max(maxi, sum);
	}

	return;
}

void isValid()//croak
{
	flag = 0;
	for (int i = 0; i < len; i++) {
		if (valid[i] == 1) continue;
		if (flag == 0 && str[i] == 'c') {
			valid[i] = 1;
			flag = 1;
		}
		else if (flag == 1 && str[i] == 'r') {
			valid[i] = 1;
			flag = 2;
		}
		else if (flag == 2 && str[i] == 'o') {
			valid[i] = 1;
			flag = 3;
		}
		else if (flag == 3 && str[i] == 'a') {
			valid[i] = 1;
			flag = 4;
		}
		else if (flag == 4 && str[i] == 'k') {
			valid[i] = 1;
			flag = 0;
			i = -1;
		}
	}

	for (int i = 0; i < len; i++) {
		if (valid[i] == 0) {
			flag = 1;
			return;
		}
	}

	flag = 0;
	return;
}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) 
	{
		cout << "#" << tc << " ";
		init();
		if (flag == 1) {
			cout << -1 << "\n";
			continue;
		}
		isValid();
		if (flag == 1) cout << -1 << "\n";
		else cout << maxi << "\n";
	}
}