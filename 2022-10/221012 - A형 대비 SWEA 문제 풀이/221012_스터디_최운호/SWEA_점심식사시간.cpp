#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct pos {
	int y;
	int x;
};

int n;
int peopleCnt;

int map[10][10];

vector<pos> people;
vector<pos> stair;
vector<int> wait[2];
int minTime = 21e8;

int getTime1() {
	int result = 0;

	vector<int> temp1;

	for (int loop : wait[0]) {
		temp1.push_back(loop);
	}

	sort(temp1.begin(), temp1.end(), greater<int>());

	int stLen = map[stair[0].y][stair[0].x];

	int cnt = 0;

	queue<int> q;

	while (1) {
		for (int i = temp1.size() - 1; i >= 0; i--) {
			if (temp1[i] <= result && q.size() < 3) {
				q.push(0);
				temp1.pop_back();
			}
		}

		for (int i = 0; i < q.size(); i++) {
			int now = q.front();
			q.pop();
			now++;
			if (now == stLen) {
				i--;
				cnt++;
				continue;
			}
			q.push(now);
		}

		result++;

		if (cnt >= wait[0].size()) break;
	}

	return result;
}

int getTime2() {
	int result = 0;

	vector<int> temp2;

	for (int loop : wait[1]) {
		temp2.push_back(loop);
	}

	sort(temp2.begin(), temp2.end(), greater<int>());

	int stLen = map[stair[1].y][stair[1].x];

	int cnt = 0;

	queue<int> q;

	while (1) {
		for (int i = temp2.size() - 1; i >= 0; i--) {
			if (temp2[i] <= result && q.size() < 3) {
				q.push(0);
				temp2.pop_back();
			}
		}

		
		for (int i = 0; i < q.size(); i++) {
			int now = q.front();
			q.pop();
			now++;
			if (now == stLen) {
				i--;
				cnt++;
				continue;
			}
			q.push(now);
		}

		result++;


		if (cnt >= wait[1].size()) break;

	}

	return result;
}

void dfs(int lev) {
	if (lev == peopleCnt) {
		int t1 = 0;
		int t2 = 0;
		if (wait[0].size() != 0) t1 = getTime1();
		if (wait[1].size() != 0) t2 = getTime2();
		int result = max(t1, t2);
		minTime = min(minTime, result);
		return;
	}

	for (int i = 0; i < 2; i++) {
		int distance = abs(people[lev].y - stair[i].y) + abs(people[lev].x - stair[i].x) + 1;
		wait[i].push_back(distance);
		dfs(lev + 1);
		wait[i].pop_back();
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		minTime = 21e8;
		peopleCnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					peopleCnt++;
					people.push_back({ i,j });
				}
				else if (map[i][j] > 1) {
					stair.push_back({ i,j });
				}
			}
		}
		dfs(0);

		cout << "#" << t << " " << minTime << '\n';

		people.clear();
		stair.clear();
		wait[0].clear();
		wait[1].clear();
	}

	return 0;
}