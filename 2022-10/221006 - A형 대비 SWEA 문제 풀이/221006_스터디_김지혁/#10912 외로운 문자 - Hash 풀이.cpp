#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef unordered_map<char, int> umch;

bool cmp(pair<char, int>& t, pair<char, int>& v) {
	return t.first < v.first;
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		umch um;
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			char ch = str[i];
			um[ch]++;
		}

		int flag = 0;
		vector<pair<char, int>> v(um.begin(), um.end());
		sort(v.begin(), v.end(), cmp);
		cout << "#" << tc << " ";
		for (auto& i : v) {
			if (i.second % 2 == 1) {
				cout << i.first;
				flag = 1;
			}
		}
		if (flag == 0) cout << "Good";
		cout << "\n";
	}

	return 0;
}