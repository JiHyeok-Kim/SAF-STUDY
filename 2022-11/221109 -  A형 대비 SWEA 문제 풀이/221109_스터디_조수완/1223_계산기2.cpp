#include <iostream>
#include <stack>
#include <string>
using namespace std;
int calc(int a, int b, char op) {
	if (op == '+')return a + b;
	else return a * b;
}
void solve() {
	for (int t = 1; t <= 10; t++) {
		int L;
		string str;
		string back;
		stack<string> s;
		cin >> L >> str;
		for (int i = 0; i < L; i++) {
			if (str[i] >= '0' && str[i] <= '9')back += str[i];
			if (str[i] == '+') {
				if (s.empty()) s.push("+");
				else {
					if (s.top() == "+") back += "+";
					else {
						back += s.top(); s.pop();
						if (s.empty())s.push("+");
						else back += "+";
					}
				}
			}if (str[i] == '*') {
				if (s.empty()) s.push("*");
				else {
					if (s.top() == "*") back += "*";
					else s.push("*");
				}
			}
		}
		while (!s.empty()) { back += s.top(); s.pop(); }
		int ans = 0;
		for (int i = 0; i < L; i++) {
			if (back[i] >= '0' && back[i] <= '9') s.push(to_string(back[i]-'0'));
			else {
				int b = stoi(s.top()); s.pop();
				int a = stoi(s.top()); s.pop();
				ans = calc(a, b, back[i]);
				s.push(to_string(ans));
				if (s.empty())break;
			}
		}
		string result = s.top(); s.pop();
		cout << "#" << t << " " << result << "\n";
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