#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <unordered_map>
using namespace std;

int T;
char in[101];

unordered_map<char, vector<int>> DB;

void Solve(int tc) {
	for (int i = 0; i < strlen(in); ++i) {
		DB[in[i]].push_back(i);
	}

	string temp = "";
	for (int i = 'a'; i <= 'z'; ++i) {
		if (DB[char(i)].size() % 2 == 0) continue;
		temp += char(i);
	}

	if (temp == "") cout << "#" << tc << " Good\n";
	else cout << "#" << tc << " " << temp << "\n";
}

void init() {
	for (int i = 'a'; i <= 'z'; ++i) {
		DB[char(i)].clear();
	}
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		init();
		cin >> in;
		Solve(tc);
	}
	return 0;
}