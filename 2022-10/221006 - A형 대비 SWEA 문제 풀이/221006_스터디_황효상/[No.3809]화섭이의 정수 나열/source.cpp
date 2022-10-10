#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <memory.h>

using namespace std;
int T;
int N;
string input;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> N;
		for (int a = 0; a < N; ++a) {
			string tmp;
			cin >> tmp;
			input += tmp;

		}
		int num = 0;
		string target = to_string(num);
		while (1) {
			int ret = input.find(target);
			if (ret == -1) {
				cout << "#" << t << " " << num<<"\n";
				break;
			}
			else {
				++num;
				target = to_string(num);
			}
		}
		input = "";
	}
}
