#include <iostream>
#include <string>
using namespace std;

int n;
string str[10000];

int bs(int s, int e, string tar) {
	// 0이 될 수 있으니 last = -1
	int last = -1;
	while (s <= e) {
		int mid = (s + e) / 2;

		if (tar[mid] == '#') {
			last = mid;
			s = mid + 1;
		}
		else if (tar[mid] == '_') {
			e = mid - 1;
		}
	}
	return (last + 1);
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
		int ret = bs(0, str[i].length() - 1, str[i]);

		cout << (ret * 100) / str[i].length() << "%" << "\n";
	}

	return 0;
}