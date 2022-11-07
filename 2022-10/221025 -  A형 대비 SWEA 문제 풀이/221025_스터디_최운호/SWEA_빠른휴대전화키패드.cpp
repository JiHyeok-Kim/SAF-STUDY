#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<char> keypad[10];
string nums;
int N;
int answer;

void init() {
	int cnt = 0;
	int idx = 2;
	for (char i = 'a'; i <= 'z'; i++) {
		cnt++;
		keypad[idx].push_back(i);
		if ((idx == 7 || idx == 9) && cnt == 4) {
			idx++;
			cnt = 0;
		}
		else if ((idx != 7 && idx != 9) && cnt == 3) {
			idx++;
			cnt = 0;
		}
	}

}

int main() {
	int tc;
	cin >> tc;
	init();
	for (int t = 1; t <= tc; t++) {
		answer = 0;
		cin >> nums >> N;
		int len = nums.size();
		for (int i = 0; i < N; i++) {
			string str;
			cin >> str;
			int flag = 1;
			if (str.size() != len) continue;
			for (int j = 0; j < len; j++) {
				int num = nums[j] - '0';
				int ret = 0;
				for (char loop : keypad[num]) {
					if (loop == str[j]) {
						ret = 1;
						break;
					}
				}
				if (ret == 0) {
					flag = 0;
					break;
				}
			}
			if (flag) answer++;
		}

		cout << "#" << t << " " << answer << '\n';
	}
	return 0;
}