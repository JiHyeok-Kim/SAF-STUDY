#include <iostream>
#include <stack>
#include <string>
using namespace std;

int N, ans;
string str, postfix;

void init()
{
	ans = 0;
	postfix = "";
	cin >> str;
}

void Postfix()
{
	stack<char> temp;
	for (int i = 0; i < N; i++) {
		if ('0' <= str[i] && str[i] <= '9') postfix += str[i];
		else if (str[i] == '(') temp.push(str[i]);
		else if (str[i] == ')') {
			while (1)
			{
				char ch = temp.top();
				temp.pop();
				if (ch == '(') break;
				postfix += ch;
			}

		}
		else if (temp.empty()) temp.push(str[i]);
		else if (temp.top() == '(') temp.push(str[i]);
		else if (str[i] < temp.top()) temp.push(str[i]);
		else if (str[i] >= temp.top()) {
			char ch = temp.top();
			temp.pop();
			postfix += ch;
			while (!temp.empty())
			{
				if (temp.top() == '(') break;
				if (str[i] < temp.top()) break;
				ch = temp.top();
				temp.pop();
				postfix += ch;
			}
			temp.push(str[i]);
		}
	}
	while (!temp.empty())
	{
		char ch = temp.top();
		temp.pop();
		postfix += ch;
	}

	return;
}

void Calc()
{
	stack<int> temp;
	for (int i = 0; i < postfix.length(); i++) {
		if ('0' <= postfix[i] && postfix[i] <= '9') temp.push(postfix[i] - '0');
		else {
			int b = temp.top();
			temp.pop();
			int a = temp.top();
			temp.pop();
			if (postfix[i] == '+') temp.push(a + b);
			else if (postfix[i] == '*') temp.push(a * b);
		}
	}

	ans = temp.top();
	return;
}

void solve()
{
	Postfix();
	Calc();

	return;
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc = 0;
	while (cin >> N)
	{
		tc++;
		init();
		solve();
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}