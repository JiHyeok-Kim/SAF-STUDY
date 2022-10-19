#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <algorithm>
using namespace std;


int T;
int study[7];
int ans = 21e8;
int target;
int course;
vector<int> open;

void getAnswer(int idx) {
	
	if (course >= target) {
		int tmp = 0;
		for (int a = 0; a < 7; ++a) {
			int index = (idx + a) % 7;
			if (study[index] == 1) {
				++tmp;
				if (tmp == target) {
					ans = min(ans, a + 1);
				}
			}
		}
	}
	else {
		int weeks = target / course;
		int ttarget = target % course;
		if (ttarget == 0) {
			ttarget = course;
			for (int a = 0; a < 7; ++a) {
				int index = (idx + a) % 7;
				if (study[index] == 1) {
					--ttarget;
					if (ttarget == 0) {
						ans = min(ans, (weeks-1) * 7 + a + 1);
					}
				}
			}
		}
		else {
			for (int a = 0; a < 7; ++a) {
				int index = (idx + a) % 7;
				if (study[index] == 1) {
					--ttarget;
					if (ttarget == 0) {
						ans = min(ans, weeks * 7 + a + 1);
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> target;
		course = 0;
		ans = 21e8;
		for (int a = 0; a < 7; ++a) {
			cin >> study[a];
			if (study[a] == 1) {
				++course;
				open.push_back(a);
			}
		}
		for (int startDay = 0; startDay < open.size(); ++startDay) {
			getAnswer(open[startDay]);
		}
		cout << ans << "\n";
		open.clear();

	}
	return 0;
}
