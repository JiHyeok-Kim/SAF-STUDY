#include <iostream>
#include <cstring>
using namespace std;

int N, sumA, cnt;
int arr[9];
bool used[9];

void init()
{
	sumA = 0;
	memset(arr, 0, sizeof(arr));

	cin >> N;
	for (int i = 0; i < N; i++) 
	{
		cin >> arr[i];
		sumA += arr[i];
	}

	return;
}

void DFS(int lev, int sumL, int sumR)
{
	if (sumL < sumR) return;
	if (lev != N && sumL >= sumA - sumL)
	{
		int add = 1;
		for (int i = 0; i < N - lev; i++)
		{
			add *= (N - lev - i) * 2;
		}
		cnt += add;

		return;
	}
	if (lev == N)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (used[i] == true) continue;
		used[i] = true;

		if (sumL < sumR + arr[i]) DFS(lev + 1, sumL + arr[i], sumR);
		else {
			DFS(lev + 1, sumL + arr[i], sumR);
			DFS(lev + 1, sumL, sumR + arr[i]);
		}

		used[i] = false;
	}

	return;
}

int solve()
{
	cnt = 0;
	for (int i = 0; i < N; i++) 
	{
		used[i] = true;
		DFS(1, arr[i], 0);
		used[i] = false;
	}
	
	return cnt;
}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for(int tc = 1; tc<= T; tc++)
	{
		init();
		cout << "#" << tc << " " << solve() << "\n";
	}

	return 0;
}