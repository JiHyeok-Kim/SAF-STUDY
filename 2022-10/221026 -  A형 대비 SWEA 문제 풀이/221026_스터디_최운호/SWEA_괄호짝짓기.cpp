#include <iostream>
#include <string>
#include <stack>
using namespace std;

int N;
string str;
stack<char> stk;

bool check() {
	int valid[4] = { 0 };
	for (char ch : str) {
		if (ch == '{' || ch == '(' || ch == '[' || ch == '<') {
			stk.push(ch);
		}
		else {
			char tmp = stk.top();
			if (tmp == '{' && ch == '}') stk.pop();
			else if (tmp == '[' && ch == ']') stk.pop();
			else if (tmp == '(' && ch == ')') stk.pop();
			else if (tmp == '<' && ch == '>') stk.pop();
			else return false;
		}
	}
	return true;
}

int main()
{
	for (int t = 1; t <= 10; t++) {
		int flag = 1;
		cin >> N;
		cin >> str;
		if (!check()) flag = 0;

		cout << "#" << t << " " << flag << '\n';
		while (!stk.empty()) stk.pop();
	}

	return 0;
}