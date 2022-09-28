#include <iostream>
#include <string>
using namespace std;

int map[49][49];

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < n; j++) {
				map[i][j] = str[j] - '0';
			}
		}
		int start = n / 2;
		int val = 0;

		int result = 0;
		for (int i = 0; i < n; i++) {
			for (int j = start - val; j <= start + val; j++) {
				result += map[i][j];
			}
			if (i < n / 2) val++;
			else val--;
		}

		cout << "#" << t << " " << result << '\n';
	}
	return 0;
}