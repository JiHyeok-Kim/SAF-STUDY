#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> v;

void init()
{
	cin >> N >> M;
	vector<vector<int>> temp(N + 1);
	v = temp;
	for (int i = 0; i < M; i++) {
		int y, x;
		cin >> y >> x;
		v[y].push_back(x);
		v[x].push_back(y);
	}

	return;
}

int ans()
{
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			for (int k = j + 1; k <= N; k++) {
				if (v[i].size() == 0) continue;
				if (find(v[i].begin(), v[i].end(), j) == v[i].end()) continue;
				if (v[j].size() == 0) continue;
				if (find(v[j].begin(), v[j].end(), k) == v[j].end()) continue;
				if (v[k].size() == 0) continue;
				if (find(v[k].begin(), v[k].end(), i) == v[k].end()) continue;
				cnt++;
			}
		}
	}

	return cnt;
}

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
		init();
		cout << "#" << tc << " " << ans() << "\n";
	}


	return 0;
}