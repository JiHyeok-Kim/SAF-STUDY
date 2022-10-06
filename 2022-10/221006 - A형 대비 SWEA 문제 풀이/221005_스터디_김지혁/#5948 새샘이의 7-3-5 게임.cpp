#include <iostream>
#include <cstring> 
#include <algorithm>
using namespace std;

int num[7];
int bucket[5];
bool used[7] = { false };

void dfs(int idx, int lev)
{
	if (lev == 3)
	{
		int sum = 0;
		for (int i = 0; i < 7; i++)
		{
			if (used[i] == true) sum += num[i];
		}
		for (int i = 0; i < 5; i++)
		{
			if (sum == bucket[i]) return;
		}
		if (sum > bucket[0]) bucket[0] = sum;
		sort(bucket, bucket + 5);

		return;
	}

	for (int i = idx; i < 7; i++)
	{
		if (used[i] == true) continue;
		used[i] = true;
		dfs(i, lev + 1);
		used[i] = false;
	}

	return;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		memset(bucket, 0, sizeof(bucket));
		for (int i = 0; i < 7; i++)
		{
			cin >> num[i];
		}

		dfs(0, 0);
		sort(bucket, bucket + 5);
		cout << "#" << tc << " " << bucket[0] << "\n";
	}

	return 0;
}