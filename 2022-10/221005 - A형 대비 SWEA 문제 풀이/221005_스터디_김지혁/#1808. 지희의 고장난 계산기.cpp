#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> num;
string Num;
int L, flagA, ans, mini;

void init()
{
	ans = 0;
	flagA = 0;
	mini = 21e8;
	num.clear();
	for (int i = 0; i < 10; i++) {
		int n;
		cin >> n;
		if (n == 1) num.push_back(i);
	}
	cin >> Num;

	return;
}

int isValid(int len, string N)
{
	int flag = 0;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < num.size(); j++)
		{
			char ch = '0' + num[j];
			if (N[i] == ch) {
				flag++;
				break;
			}
		}
	}
	if (flag == len) return 1;

	return 0;
}

void dfs(int lev, int len, int t, string N)
{
	if (isValid(len, N) == 1) {
		ans = lev + len + t;
		if (ans < mini) mini = ans;
		flagA = 1;
		return;
	}
	
	int nN = stoi(N);
	for (int i = sqrt(nN); i >= 1; i--) {
		if (i == 1) return;
		if (nN % i == 0) {
			string sN = to_string(i);
			int lsN = sN.size();
			if (isValid(lsN, sN) == 1) {
				int n = nN / i;
				string sn = to_string(n);
				dfs(lev + 1, sn.size(), t + lsN, sn);
			}
		}
	}

	return;
}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) 
	{
		init();
		L = Num.size();

		dfs(0, L, 1, Num);
		cout << "#" << tc << " ";
		if (flagA == 0) cout << -1 << "\n";
		else cout << mini << "\n";
	}

	return 0;
}