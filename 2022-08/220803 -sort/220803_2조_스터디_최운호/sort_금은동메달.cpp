#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct info {
	string name;
	int score;
	int idx;
};
vector<info> v;

bool compare(info t, info c) {
	if (t.score > c.score) return 1;
	if (t.score < c.score) return 0;

	if (t.idx > c.idx) return 1;
	if (t.idx < c.idx) return 0;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		int scr;
		cin >> str >> scr;
		v.push_back({ str, scr, i });

		sort(v.begin(), v.end(), compare);

		for (int i = 0; i < v.size(); i++) {
			if (i > 2) continue;
			cout << v[i].name << " ";
		}
		cout << '\n';
	}

	return 0;

}