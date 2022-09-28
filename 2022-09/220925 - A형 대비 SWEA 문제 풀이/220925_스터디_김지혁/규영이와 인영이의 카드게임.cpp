#include <iostream>
using namespace std;

int C1[9], C2[9];
int win, lose;

int pathC2[9];
int used[9];

void init()
{
	int card[19] = { 0 };
	for (int i = 0; i < 9; i++)
	{
		cin >> C1[i];
		card[C1[i]]++;
	}

	int j = 0;
	for (int i = 1; i <= 18; i++)
	{
		if (card[i] == 1) continue;
		C2[j] = i;
		j++;
	}

	return;
}

void dfs(int lev, int sumW, int sumL)
{
	if (lev == 9)
	{
		if (sumW > sumL) win++;
		else if (sumL > sumW) lose++;

		return;
	}

	for (int i = 0; i < 9; i++)
	{
		if (used[i] == 1) continue;

		pathC2[lev] = C2[i];
		used[i] = 1;
		
		// 가지치기 : DFS를 승패에 따라 두갈래로 보내기
		if (C1[lev] > pathC2[lev]) {
			dfs(lev + 1, sumW + C1[lev] + pathC2[lev], sumL);
		}
		else {
			dfs(lev + 1, sumW, sumL + C1[lev] + pathC2[lev]);
		}

		used[i] = 0;
		pathC2[lev] = 0;
	}

	return;
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		win = 0, lose = 0;

		init();
		dfs(0, 0, 0);

		cout << "#" << tc << " " << win << " " << lose << "\n";
	}

	return 0;
}