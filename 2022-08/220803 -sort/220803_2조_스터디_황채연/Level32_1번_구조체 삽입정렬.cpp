#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
	int num;
	char ch;
}NODE;
vector<NODE> v;

bool compare(NODE t, NODE v) {
	if (t.num < v.num) return 1;
	if (t.num > v.num) return 0;
	if (t.num == v.num) {
		return t.ch < v.ch;
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int t_num;
		char t_ch;
		cin >> t_num >> t_ch;
		v.push_back({ t_num, t_ch });
	}

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; ++i) {
		cout << v[i].num << " " << v[i].ch << "\n";
	}
	return 0;
}