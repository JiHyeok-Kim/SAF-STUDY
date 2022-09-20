#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int n;
		cin >> n;

		int num[101] = { 0 };
		for (int i = 0; i < 1000; i++)
		{
			int score;
			cin >> score;
			num[score]++;
		}

		int ans;
		int idx = -1;
		int maxi = 0;
		for (auto& i : num)
		{
			idx++;
			if (i >= maxi) {
				maxi = i;
				ans = idx;
			}
		}

		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}