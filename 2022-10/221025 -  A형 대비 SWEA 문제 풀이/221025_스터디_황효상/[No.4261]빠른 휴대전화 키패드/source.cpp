#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>

using namespace std;

int T;
string input;
int N;

char nums[10][3] = {
	"",
	"",
	"ac",
	"df",
	"gi",
	"jl",
	"mo",
	"ps",
	"tv",
	"wz"
};




int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
//	freopen("input.txt", "r", stdin);
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		cin >> input >> N;
		int ans = 0;
		for (int a = 0; a < N; ++a) {
			string tmp;
			cin >> tmp;
			if (tmp.length() != input.length()) continue;

			int flag = 1;
			for (int b = 0; b < input.length(); ++b) {
				int idx = input[b] - '0';
				if (nums[idx][0] > tmp[b] || nums[idx][1] < tmp[b]) {
					flag = 0;
					break;
				}
			}
			if (flag)
				++ans;
		}
		cout << "#"<<t<<" "<<ans << "\n";
	}
}
