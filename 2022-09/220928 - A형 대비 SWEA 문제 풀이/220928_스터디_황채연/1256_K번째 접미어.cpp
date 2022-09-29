#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int T, K;
string in;
vector<string> v;

bool compare(string t, string v) {
	return t < v;
}

void Solve(int tc) {
	v.clear();
	int start = 0;
	while (1) {
		v.push_back(in);
		if (in.size() == 1) break;
		string temp = in.substr(1, in.size() - 1);
		in = temp;
	}

	sort(v.begin(), v.end(), compare);
	if (K >=v.size()) cout << "#" << tc << " " << "none" << "\n";
	else cout << "#" << tc << " " << v[K - 1] << "\n";
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> K >> in;
		Solve(tc);
	}
	return 0;
}