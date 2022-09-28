#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

int N;
int map[50][50];
int tot;
void input() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> N;
		
		memset(map, 0, sizeof(map));
		tot = 0;
		for (int a = 0; a < N; ++a) {
			string tmp;
			cin >> tmp;
			for (int b = 0; b < tmp.length(); ++b) {
				map[a][b] =tmp[b]-'0';
				tot += map[a][b];
			}
		}

		int out_sider = 0;
		int center = N / 2;
		int left_wall = center;
		int right_wall = center;
		for (int a = 0; a < center; ++a) {
			for (int b = 0; b < left_wall; ++b) {
				out_sider += map[a][b];
			}
			for (int b = right_wall+1; b < N; ++b) {
				out_sider += map[a][b];
			}
			--left_wall;
			++right_wall;
		}
		left_wall = 1;
		right_wall = N - 2;
		for (int a = center + 1; a < N; ++a) {
			
			for (int b = 0; b < left_wall; ++b) {
				out_sider += map[a][b];
			}
			for (int b = right_wall + 1; b < N; ++b) {
				out_sider += map[a][b];
			}
			++left_wall;
			--right_wall;
		}
		cout << "#"<<t<< " "<<tot - out_sider << "\n";

	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	input();
	return 0;
}
