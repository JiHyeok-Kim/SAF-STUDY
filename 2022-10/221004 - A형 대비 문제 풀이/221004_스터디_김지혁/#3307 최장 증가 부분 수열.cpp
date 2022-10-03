#include <iostream>
#include <vector>
using namespace std;

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
		int N;
		int num[1000] = { 0 };
		vector<int> list;
		int ans = 0;

		cin >> N;
		for (int i = 0; i < N; i++){
			cin >> num[i];
		}

		list.push_back(num[0]);
		for (int i = 1; i < N; i++) {
			int len = list.size();
			int n;
			for (int j = 0; j < len; j++) {
				if (num[i] < list[j]) {
					list[j] = num[i];
					break;
				}
				if (j == len - 1) list.push_back(num[i]);
			}
		}

		ans = list.size();
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}