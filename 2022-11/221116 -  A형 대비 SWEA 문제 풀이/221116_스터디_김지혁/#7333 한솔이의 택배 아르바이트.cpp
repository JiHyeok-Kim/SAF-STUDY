#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int arr[100];

void init()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N, greater<int>());
	return;
}

int solve()
{
	int idx, add, cnt;
	cnt = 0;
	idx = add = -1;
	while (idx + add + 2 < N)
	{
		if (arr[++idx] < 50) {
			int num = ceil(50 / float(arr[idx]));
			add += --num;
		}
		cnt++;
	}

	if (idx + add + 2 > N) cnt--;
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
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		cout << "#" << tc << " " << solve() << "\n";
	}

	return 0;
}