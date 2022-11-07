#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string S;
int N, L, cnt;
unordered_map<char, int> um;

void input()
{
	int idx = 5;
	for (char ch = 'a'; ch <= 'z'; ch++) {
		if (ch == 'q' || ch == 'x') idx--;
		idx++;
		int n = idx / 3;
		um[ch] = n;
	}

	return;
}

int isValid(string str, int len)
{
	for (int i = 0; i < len; i++)
	{
		int n = S[i] - '0';
		if (um[str[i]] != n) return 0;
	}

	return 1;
}

void init()
{
	cnt = 0;
	cin >> S >> N;
	L = S.length();
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		int len = str.length();
		if (len != L) continue;
		cnt += isValid(str, len);
	}

	return;
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	input();

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		cout << "#" << tc << " " << cnt << "\n";
	}
}