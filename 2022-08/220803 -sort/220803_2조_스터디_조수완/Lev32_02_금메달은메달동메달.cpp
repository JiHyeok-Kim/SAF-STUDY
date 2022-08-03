#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct node {
	string name;
	int score;
	int x;
};

node info[1000000];

bool compare(node t, node v) {
	if (t.score != v.score) return t.score > v.score;
	else return t.x > v.x;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> info[i].name >> info[i].score;
		info[i].x = i;
		sort(info, info + i + 1, compare);
		for (int j = 0; j < 3; j++) {
			cout << info[j].name << " ";
		}
		cout << '\n';
	}


	return 0;
}