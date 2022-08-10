#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dat[200];
char path[200];
string compare[1000];

struct Tree {
	char left;
	char right;
};

vector<char> tree;
vector<char> alpha;
vector<Tree> v(200);

int n, m;

void dfs(char now) {
	alpha.push_back(now);
	if (v[now].left != '#' && v[now].left) dfs(v[now].left);
	if (v[now].right != '#' && v[now].right) dfs(v[now].right);
}

bool cmp(string a, string b) {
	int a_len = a.size();
	int b_len = b.size();
	int len;
	if (a_len > b_len) len = b_len;
	else len = a_len;

	for (int i = 0; i < len; i++) {
		int a_idx = 99, b_idx = 99;
		for (int j = 0; j < alpha.size(); j++) {
			if (a[i] == alpha[j]) a_idx = j;
			if (b[i] == alpha[j]) b_idx = j;
		}
		if (a_idx < b_idx) return true;
		if (a_idx > b_idx) return false;
	}

	if (a_len < b_len) return true;
	if (a_len > b_len) return false;

	return false;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c, l, r;
		cin >> c >> l >> r;
		tree.push_back(c);
		v[c].left = l;
		v[c].right = r;
		dat[l] = 1;
		dat[r] = 1;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> compare[i];
	}
	char first;

	for (int i = 0; i < tree.size(); i++) {
		if (dat[tree[i]] == 0) {
			first = tree[i];
		}
	}

	dfs(first);

	sort(compare, compare + m, cmp);

	for (int i = 0; i < m; i++) {
		cout << compare[i] << '\n';
	}

	return 0;
}