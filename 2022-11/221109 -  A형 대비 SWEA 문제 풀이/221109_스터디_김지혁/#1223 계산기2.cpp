#include <iostream>
#include <string>
using namespace std;

int N;
string str;

int num(int idx) {
	return str[idx] - '0';
}

int gop(int* p, int idx) {
	int n = num(idx - 1);
	for (int i = idx; i < N; i++) {
		if (str[i] == '*') {
			*p = i;
			continue;
		}
		else if (str[i] == '+') return n;
		n *= num(i);
	}
	return n;
}

int solve()
{
	int ans = num(0);
	for (int i = 1; i < N; i += 2) {
		if (str[i] == '+') ans += num(i + 1);
		if (str[i] == '*') {
			ans -= num(i - 1);
			ans += gop(&i, i);
		}
	}

	return ans;
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int tc = 0;
	while (cin >> N)
	{
		tc++;
		cin >> str;
		cout << "#" << tc << " " << solve() << "\n";
	}

	return 0;
}