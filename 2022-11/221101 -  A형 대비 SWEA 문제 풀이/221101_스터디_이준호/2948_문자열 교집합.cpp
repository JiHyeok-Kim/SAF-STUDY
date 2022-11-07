#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> um;

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int tcCnt;
	cin >> tcCnt;
	int n, m, ans;
	string temp;
	for (int tc = 1; tc <= tcCnt; tc++) {
		ans = 0;
		um.clear();
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			um[temp]++;
		}

		for (int i = 0; i < m; i++) {
			cin >> temp;
			if (um.count(temp)) ans++;
		}
		cout << "#" << tc << " " << ans << "\n";
	}


	return 0;
}