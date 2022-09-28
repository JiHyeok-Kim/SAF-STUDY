#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> v;
int k;

bool cmp(string a, string b) {
	int aLen = a.size();
	int bLen = b.size();
	int len = 0;
	if (aLen > bLen) len = bLen;
	else len = aLen;

	for (int i = 0; i < len; i++) {
		if (a[i] < b[i]) return true;
		else if (a[i] > b[i]) return false;
	}

	return aLen < bLen;
}

void getWord(string st) {
	int size = st.size();
	int idx = 0;

	for (int i = 0; i < st.size(); i++) {
		string temp = st.substr(idx++, size--);
		v.push_back(temp);
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		string str;
		cin >> k >> str;

		getWord(str);

		sort(v.begin(), v.end(), cmp);

		cout << "#" << t << " " << v[k-1] << '\n';

		v.clear();
	}

	return 0;
}