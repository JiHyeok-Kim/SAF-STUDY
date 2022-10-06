#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int num[7];
int used[7];
int makeNum[700];

vector<int> v;

void dfs(int lev, int n) {
	if (lev == 3) {
		if (makeNum[n] == 1) return;
		makeNum[n] = 1;
		v.push_back(n);
		return;
	}

	for (int i = 0; i < 7; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		dfs(lev + 1, n + num[i]);
		used[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		for (int i = 0; i < 7; i++) {
			cin >> num[i];
		}

		memset(makeNum, 0, sizeof(int) * 700);

		dfs(0, 0);

		sort(v.begin(), v.end(), greater<>());

		cout << "#" << t << " " << v[4] << '\n';

		v.clear();
	}
	return 0;
}