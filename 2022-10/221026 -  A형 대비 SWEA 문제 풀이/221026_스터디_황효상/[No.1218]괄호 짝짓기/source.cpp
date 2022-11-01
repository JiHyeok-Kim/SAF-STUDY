#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <stack>

using namespace std;


stack<char> st;
string input;
int leng;
void init() {
	while (st.size() > 0) {
		st.pop();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
//	freopen("input.txt", "r", stdin);

	
	for (int t = 1; t <= 10; ++t) {
		cin >> leng >> input;
		init();
		int flag = 1;
		for (int a = 0; a < input.length(); ++a) {
			if (input[a] == '(' || input[a] == '{' || input[a] == '<' || input[a] == '[') {
				st.push(input[a]);
			}
			else {
				char target = st.top();
				st.pop();
				if (input[a] == ')') {
					if (target != '(') {
						flag = 0;
						break;
					}
				}
				else if (input[a] == '}') {
					if (target != '{') {
						flag = 0;
						break;
					}

				}
				else if (input[a] == '>') {
					if (target != '<') {
						flag = 0;
						break;
					}
				}
				else {
					if (target != '[') {
						flag = 0;
						break;
					}
				}
			}
		}
		if (flag && st.size() == 0) {
			cout << "#" << t << " 1\n";
		}
		else {
			cout << "#" << t << " 0\n";
		}
	}
}
