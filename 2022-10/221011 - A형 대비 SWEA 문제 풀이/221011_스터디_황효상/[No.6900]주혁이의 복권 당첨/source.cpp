#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

int T, N, M;
vector<string> toto;
int winnings[101];

void init() {
	toto.clear();
	memset(winnings, 0, sizeof(winnings));
}
bool comp(int idx, string target) {
	for (int a = 0; a < toto[idx].length(); ++a) {
		if (toto[idx][a] == '*')
			continue;
		else {
			if (toto[idx][a] != target[a])
				return 0;
		}
	}
	return 1;
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("Input.txt", "r", stdin);

	cin >> T;
	for (int t = 1; t <= T; ++t) {
		init();
		cin >> N >> M;
		for (int a = 0; a < N; ++a) {
			string tmp;
			int win;
			cin >> tmp >> win;
			toto.push_back(tmp);
			winnings[a] = win;
		}
		int sum = 0;
		for (int a = 0; a < M; ++a) {
			string tmp;
			cin >> tmp;
			for(int b = 0; b < N; ++b){
				if (comp(b, tmp)) {
					sum += winnings[b];
				}

			}
		}
		cout <<"#"<<t<<" "<< sum << "\n";
	}
	return 0;
}
