#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int N;
char num[10000];
int down;

void init()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}

	return;
}

void dfs(int lev)
{
	if (lev == N + 1) {
		return;
	}

	if (lev == 1) down = 1;
	else down = 0;
	for (int i = pow(10, lev - 1) - down; i < pow(10, lev); i++)
	{
		int flag = 0;
		for (int j = 0; j < N; j++) {
			string str;
			for (int k = 0; k < lev; k++) {
				if (j + k >= N) break;
				str += num[j + k];
			}
			if (str == to_string(i)) flag = 1;
		}
		if (flag == 0) {
			cout << i << "\n";
			return;
		}
	}

	dfs(lev + 1);

	return;
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();

		cout << "#" << tc << " ";
		dfs(1);
	}

	return 0;
}