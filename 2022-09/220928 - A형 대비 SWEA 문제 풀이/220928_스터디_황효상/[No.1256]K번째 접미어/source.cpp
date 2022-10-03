#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int T,K;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

	cin >> T;
	string s;

	for (int t = 1; t <= T; ++t) {
		cin >> K;;
		cin >> s;
		vector<string> list;
		string tmp = "";
		for (int a = s.length()-1; a>=0; --a) {
			tmp = s[a]+tmp;
			list.push_back(tmp);
		}

		sort(list.begin(), list.end());

		cout << "#" << t << " " << list[K-1] << "\n";
	}


	return 0;
}
