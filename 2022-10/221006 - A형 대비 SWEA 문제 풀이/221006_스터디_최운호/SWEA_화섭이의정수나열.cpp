#include <iostream>
#include <string>
using namespace std;

int n;
char num[1000];

bool cmp(int target, int idx, int len) {
	string number = "";

	for (int i = idx; i < idx + len; i++) {
		number += num[i];
	}
	int tmp = stoi(number);

	return tmp == target;
}

int run() {
	int val = 0;

	while (1) {
		string str = to_string(val);
		int len = str.size();
		int flag = 0;
		for (int i = 0; i <= n - len; i++) {
			if (cmp(val, i, len)) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) return val;

		val++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}

		int answer = run();

		cout << "#" << t << " " << answer << '\n';
	}

	return 0;
}