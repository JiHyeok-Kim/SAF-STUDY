#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int k;
string str;
vector<string> tong;
string ans;

void solve() {
	string temp;
	for (int i = 0; i < str.length(); i++) {
		temp = str.substr(i, str.length());
		tong.push_back(temp);
	}
	sort(tong.begin(), tong.end());
	if (tong[k-1] == "") ans = "none";
	else ans = tong[k-1];
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		cin >> k >> str;
		tong.clear();
		solve();

		cout << "#" << tc << " " << ans << "\n";
	}


	return 0;
}