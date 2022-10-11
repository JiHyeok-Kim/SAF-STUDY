#include <iostream>
#include <unordered_map>
using namespace std;

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
		int N, M, ans = 0;
		cin >> N >> M;
		unordered_map<string, int> um;
		for (int i = 0; i < N; i++) {
			string str;
			int n;
			cin >> str >> n;
			um[str] = n;
		}

		for (int i = 0; i < M; i++) {
			string str;
			cin >> str;
			for (auto& j : um) {
				int flag = 0;
				for (int k = 0; k < 8; k++) {
					if (j.first[k] == '*') continue;
					if (j.first[k] != str[k]) { flag = 1; break; }
				}
				if (flag == 0) { ans += j.second; break; }
			}
		}

		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}