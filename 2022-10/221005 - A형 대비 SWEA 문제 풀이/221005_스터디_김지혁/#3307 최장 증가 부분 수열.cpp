#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		int num[1000] = { 0 };
		vector<int> lis;
		int ans = 0;

		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> num[i];
		}

		lis.push_back(num[0]);
		for (int i = 1; i < N; i++) {
			int len = lis.size();
			int n;
			for (int j = 0; j < len; j++) {
				if (num[i] < lis[j]) {
					lis[j] = num[i];
					break;
				}
				if (j == len - 1) lis.push_back(num[i]);
			}
		}
		ans = lis.size();
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}