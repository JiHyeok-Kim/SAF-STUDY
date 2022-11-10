#include <iostream>
#include <string>
#include <stack>
using namespace std;
int L;
int a[130];
int calc(int a, int b, char op) {
	if (op == '+') return a + b;
	else return a * b;
}
void solve() {
	a['('] = 0; a['+'] = 1; a['*'] = 2;
	for (int t = 1; t <= 10; t++) {
		stack<char>s;
		string str;
		string back;
		cin >> L >> str;
		for (int i = 0; i < L; i++) {
			if (str[i] >= '0'&&str[i] <= '9')back += str[i];
			else if (str[i] == '(') s.push(str[i]);
			else if (str[i] == ')') {
				while (s.top() != '(') { back += s.top(); s.pop(); }
				if (s.top() == '(')s.pop();
			}
			else {
				if (s.empty())s.push(str[i]);
				else {
					if (a[s.top()] < a[str[i]]) s.push(str[i]);
					else {
						back += s.top(); s.pop();
						s.push(str[i]);
					}
				}
			}
		}
		while (!s.empty()) {
			if (s.top() == '(') { s.pop(); continue; }
			back += s.top(); s.pop();
		}
		stack<string> s1;
		for (int i = 0; i < back.length(); i++) {
			if (back[i] >= '0'&&back[i] <= '9')s1.push(to_string(back[i] - '0'));
			else {
				int b = stoi(s1.top()); s1.pop();
				int a = stoi(s1.top()); s1.pop();
				int tmp = calc(a, b, back[i]);
				s1.push(to_string(tmp));
			}
		}
		cout << "#" << t << " " << s1.top() << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}