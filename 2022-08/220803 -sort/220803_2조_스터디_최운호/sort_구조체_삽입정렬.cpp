#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int n;
	char ch;
};

vector<Node> list;

bool compare(Node t, Node v) {
	if (t.n < v.n) return 1;
	if (t.n > v.n) return 0;

	return t.ch < v.ch;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		char ch;
		cin >> num >> ch;
		list.push_back({ num,ch });
	}

	sort(list.begin(), list.end(), compare);

	for (Node loop : list) {
		cout << loop.n << " " << loop.ch << '\n';
	}

	return 0;
}