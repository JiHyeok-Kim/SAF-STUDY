// [S/W 문제해결 기본] 4일차 - 괄호 짝짓기
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
	int T = 10;
	
	for (int tc = 0; tc < T; tc++) {
		int bracket[126] = { 0 };
		int num;
		string str;
		cin >> num >> str;

		for (int i = 0; i < num; i++) {
			int dat = str[i];
			bracket[dat]++;
		}

		if (bracket['('] == bracket[')']
			&& bracket['['] == bracket[']']
			&& bracket['{'] == bracket['}']
			&& bracket['<'] == bracket['>']) {
			cout << "#" << tc + 1 << " " <<
				"1" << endl;
		}
		else {
			cout << "#" << tc + 1 << " " <<
				"0" << endl;
		}
	}
	return 0;
}