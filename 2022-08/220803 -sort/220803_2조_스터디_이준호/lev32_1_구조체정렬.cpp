#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int num;
	char ch;
};

bool compare(Node t, Node v) {
	if (t.num < v.num) return 1;
	if (t.num > v.num) return 0;
	if (t.ch < v.ch) return 1;
	if (t.ch > v.ch) return 0;

}

int main()
{
	Node arr[100];

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i].num >> arr[i].ch;
	}

	sort(arr, arr + n, compare);

	for (int i = 0; i < n; i++) {
		cout << arr[i].num << " " << arr[i].ch << endl;
	}
	return 0;
}