#include <iostream>
#include <string>
using namespace std;

int n;

int bs(string str) {
	int s = 0;
	int e = str.size() - 1;
	while (s <= e) {
		int mid = (s + e) / 2;

		if (str[mid] == '#') s = mid + 1;
		if (str[mid] == '_') e = mid - 1;
	}

	return (s * 100) / str.size();
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string fuel;
		cin >> fuel;
		int result = bs(fuel);
		cout << result << "%" << '\n';
	}
}