#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> binary;

void bs(int index) {
	int s = 0;
	int e = binary.size()-1;
	while (s <= e) {
		int mid = (s + e) / 2;

		if (binary[mid] == index) {
			cout << "O";
			return;
		}
		else if (binary[mid] > index) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	cout << "X";
	return;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		binary.push_back(temp);
	}
	int a = 2;
	sort(binary.begin(), binary.end());

	int k;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int find;
		cin >> find;
		bs(find);
	}

	

	return 0;
}