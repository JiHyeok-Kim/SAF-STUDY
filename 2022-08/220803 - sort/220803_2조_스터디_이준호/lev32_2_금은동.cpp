#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	string ch;
	int num;
	int order;
};

Node arr[1000000];

bool compare(Node t, Node v) {
	if (t.num != v.num) return t.num > v.num;
	else return t.order > v.order;
	
	
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i].ch >> arr[i].num;
		arr[i].order = i;

		sort(arr, arr + n, compare);

		for (int j = 0; j < 3; j++) {
			cout << arr[j].ch << " ";
		}
		cout << endl;;
	}

}