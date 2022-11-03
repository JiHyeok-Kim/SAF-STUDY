#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

struct note {
	int len;
	string name;
};

bool cmp(note A, note B)
{
	if (A.len < B.len) return true;
	if (A.len > B.len) return false;

	for (int i = 0; i < A.len; i++) {
		if (A.name[i] < B.name[i]) return true;
		if (A.name[i] > B.name[i]) return false;
	}

	return false;
}

int N, idx;
vector<note> v;
unordered_map<string, int> um;

void init()
{
	um.clear();
	v.clear();

	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		int tmp = str.size();
		if (um.count(str) == 0) {
			v.push_back({ tmp, str });
			um[str] = 1;
		}
	}

	sort(v.begin(), v.end(), cmp);
}

void solve(int t)
{
	cout << "#" << t << '\n';
	for (auto loop : v) {
		cout << loop.name << '\n';
	}
}

int main()
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++)
	{
		init();

		solve(t);
	}
	return 0;
}