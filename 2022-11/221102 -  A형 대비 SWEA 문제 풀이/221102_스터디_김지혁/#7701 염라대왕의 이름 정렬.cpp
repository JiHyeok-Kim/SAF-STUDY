#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool cmp(pair<string, int> t, pair<string, int> v) {
	if (t.first.length() < v.first.length()) return 1;
	else if (t.first.length() > v.first.length()) return 0;
	for (int i = 0; i < t.first.length(); i++) {
		if (t.first[i] < v.first[i]) return 1;
		else if (t.first[i] > v.first[i]) return 0;
	}
}

int N;
string str;
unordered_map<string, int> um;

void init()
{
	um.clear();
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		um[str]++;
	}

	return;
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
		init();
		vector<pair<string, int>> v(um.begin(), um.end());
		sort(v.begin(), v.end(), cmp);
		cout << "#" << tc << "\n";
		for (auto& i : v) {
			cout << i.first << "\n";
		}
	}

	return 0;
}