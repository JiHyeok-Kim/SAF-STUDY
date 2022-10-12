#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool cmp(pair<string, int> t, pair<string, int> v) {
	return t.first > v.first;
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
		int N, K;
		string str;
		unordered_map<string, int> um;
		cin >> N >> K >> str;

		K--;
		int n = N / 4;
		for (int i = 0; i < N; i++) {
			string temp;
			temp += str[N - 1];
			for (int j = 0; j < N - 1; j++) {
				temp += str[j];
			}
			str = temp;
			for (int j = 0; j < N; j += n) {
				string temp2;
				for (int k = 0; k < n; k++) {
					temp2 += str[n + k];
				}
				um[temp2]++;
			}
		}

		vector<pair<string, int>> v(um.begin(), um.end());
		sort(v.begin(), v.end(), cmp);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int num;
			int idx = n - 1 - i;
			int gop = pow(16, i);
			if (v[K].first[idx] < 58) num = (v[K].first[idx] - '0');
			else num = (v[K].first[idx] - 55);
			ans += num * gop;
		}

		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}