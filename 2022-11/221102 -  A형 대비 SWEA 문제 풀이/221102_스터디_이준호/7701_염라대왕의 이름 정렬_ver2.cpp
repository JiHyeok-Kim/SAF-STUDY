#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int N;
string temp;
unordered_map<string, int> um;
struct Node {
	string str;
	int len;
};
vector<Node> tong;


void init() {
	um.clear();
	tong.clear();
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (um.count(temp) == 1) continue;
		um[temp] = 1;
		tong.push_back({ temp, int(temp.length()) });
	}
}

bool cmp(Node t, Node v) {
	if (t.len != v.len) return t.len < v.len;
	return t.str < v.str;
}

void solve() {
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

		for (auto &i : tong) {
			cout << i.str << "\n";
		}
		/*for (int i = 0; i < tong.size(); i++) {
			cout << tong[i].str << "\n";
		}*/
		
	}
	return 0;
}