#include <iostream>
#include <stack>
using namespace std;

int N;
string str;
string in = "{[(<";
string out = "}])>";

void init()
{
	cin >> N >> str;

	return;
}

int ans()
{
	stack<char> st;
	char ch;
	int flag = 0;
	for (int i = 0; i < N; i++) {
		if (str[i] == in[0] || str[i] == in[1] || str[i] == in[2] || str[i] == in[3]) st.push(str[i]);
		else {
			ch = st.top();
			st.pop();
			flag = 1;
			for (int j = 0; j < 4; j++) {
				if (ch == in[j] && str[i] == out[j]) flag = 0;
			}
			if (flag == 1) return 0;
		}
	}

	return 1;
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	for (int t = 1; t <= 10; t++)
	{
		init();
		cout << "#" << t << " " << ans() << "\n";
	}

	return 0;
}