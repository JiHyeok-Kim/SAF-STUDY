#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int N;
string temp;
unordered_map<string, int> um;
vector<pair<string, int>> tong;

void init() {
	um.clear();
	temp.clear();
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		um[temp]++;
	}
}
bool cmp(pair<string, int> t, pair<string, int> v) {
	if (t.first.size() != v.first.size()) return t.first.size() < v.first.size();
	return t.first < v.first;
}

void solve() {
	vector<pair<string, int>> temp(um.begin(), um.end());
	tong = temp;
	sort(tong.begin(), tong.end(), cmp);
}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		init();
		input();
		solve();
		cout << "#" << tc << "\n";
		for (int i = 0; i < tong.size(); i++) {
			cout << tong[i].first << "\n";
		}
	}
	return 0;
}