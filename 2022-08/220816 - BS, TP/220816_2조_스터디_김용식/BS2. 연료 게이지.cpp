#include <iostream>
#include <string>
using namespace std;
string oil[10001];


int bs(string percent) {
	int s = 0;
	int e = percent.length() - 1;
	int perc=0;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (percent[mid] == '#') {
			perc = mid+1;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	return perc;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> oil[i];
	}
	for (int i = 0; i < n; i++) {
		int result = bs(oil[i]);
		cout << ((result) * 100)/(oil[i].length()) << "%" << '\n';
	}
	return 0;
}