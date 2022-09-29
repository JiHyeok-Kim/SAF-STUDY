#include <iostream>
#include <string>
using namespace std;

int T;
string in;

int Solve() {
	for (int i = 0; i < 10; ++i) {
		string temp = "";
		for (int j = 0; j <= i; ++j) {
			temp += in[j];
		}

		string next = "";
		for (int j = i + 1; j < i + 1 + temp.size(); ++j) {
			next += in[j];
		}

		if (temp == next) return temp.size();
	}
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> in;
		int ret = Solve();
		cout << "#" << tc << " " << ret << "\n";
	}
	return 0;
}