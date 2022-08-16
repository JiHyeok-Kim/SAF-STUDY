#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;

vector<int> v;

bool bs(int target) {
	int s = 0;
	int e = v.size() - 1;
	while (s <= e) {
		int mid = (s + e) / 2;

		if (v[mid] == target) return true;

		if (v[mid] < target) s = mid + 1;
		if (v[mid] > target) e = mid - 1;
	}

	return false;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	cin >> k;
	for (int i = 0; i < k; i++) {
		int find;
		cin >> find;
		if (bs(find)) cout << "O";
		else cout << "X";
	}

	return 0;
}
