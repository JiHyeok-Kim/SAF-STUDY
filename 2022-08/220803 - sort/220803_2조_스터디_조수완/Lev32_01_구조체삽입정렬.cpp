#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	int x;
	char ch;
};

bool compare(node t, node v) {
	if (t.x != v.x) return t.x < v.x;
	else return t.ch < v.ch;
}

int main() {
	node arr[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i].x >> arr[i].ch;

	sort(arr, arr + n, compare);

	for (int i = 0; i < n; i++) cout << arr[i].x << " " << arr[i].ch << '\n';

	return 0;
}