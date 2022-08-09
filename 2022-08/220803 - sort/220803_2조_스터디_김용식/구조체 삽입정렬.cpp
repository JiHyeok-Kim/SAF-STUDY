#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int num;
	char eng;
};

bool compare(Node t, Node v) {
	if (t.num < v.num) return 1;
	if (t.num > v.num) return 0;
	if (t.num = v.num && t.eng < v.eng) return 1;

	return 0;
}

int main() {
	int num;
	cin >> num;

	Node Arr[100];

	for (int i = 0; i < num; i++) {
		cin >> Arr[i].num >> Arr[i].eng;
	}

	sort(Arr, Arr + num, compare);
	for (int i = 0; i < num; i++) {
		cout << Arr[i].num << " " << Arr[i].eng << '\n';
	}
}