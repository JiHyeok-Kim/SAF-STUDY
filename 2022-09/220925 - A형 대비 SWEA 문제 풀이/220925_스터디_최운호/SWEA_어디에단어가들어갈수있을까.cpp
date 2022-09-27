#include <iostream>
#include <vector>
#include <string>
using namespace std;

int map[15][15];
int n, k;
int answer;

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> k;
		answer = 0;
		string correct = "";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		vector<string> v;

		for (int i = 0; i < k; i++) correct += '1';

		for (int i = 0; i < n; i++) {
			string col = "";
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 0) {
					if (col.size() > 0)	v.push_back(col);
					col = "";
					continue;
				}
				col += map[i][j] + '0';
			}
			if (col.size() > 0) v.push_back(col);
			col = "";
		}

		for (int i = 0; i < n; i++) {
			string row = "";
			for (int j = 0; j < n; j++) {
				if (map[j][i] == 0) {
					if(row.size() > 0) v.push_back(row);
					row = "";
					continue;
				}
				row += map[j][i] + '0';
			}
			if (row.size() > 0) v.push_back(row);
			row = "";
		}

		for (auto loop : v) {
			if (loop == correct) answer++;
		}

		cout << "#" << t << " " << answer << '\n';
		v.clear();
	}
	return 0;
}
