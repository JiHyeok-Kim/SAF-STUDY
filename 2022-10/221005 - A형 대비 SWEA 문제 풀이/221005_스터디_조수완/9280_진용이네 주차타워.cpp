#include <iostream>
#include <queue>
using namespace std;
int n, m, result;
int cost[110];
int park[110];
int weight[2100];
queue<int> cmd;
queue<int> wait;
void input() {
	result = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		park[i] = 0;
		cin >> cost[i];
	}
	for (int i = 1; i <= m; i++) cin >> weight[i];
	for (int i = 0; i < 2 * m; i++) {
		int temp;
		cin >> temp;
		cmd.push(temp);
	}
}
int setParkInput(int tar) {
	for (int i = 1; i <= n; i++) {
		if (park[i] == 0) {
			park[i] = tar;
			result += weight[tar] * cost[i];
			return 1;
		}
	}
	return 0;
}
int setParkOutput(int tar) {
	for (int i = 1; i <= n; i++) {
		if (park[i]+tar==0) {
			park[i] = 0;
			return 1;
		}
	}
	return 0;
}
void solution() {
	while (!cmd.empty() || !wait.empty()) {
		if (!cmd.empty()) {
			int cmd1 = cmd.front();
			cmd.pop();
			if (cmd1 > 0) {
				int flag = setParkInput(cmd1);
				if (!flag) wait.push(cmd1);
			}
			else {
				int flag = setParkOutput(cmd1);
				if (!flag) wait.push(cmd1);
			}
		}
		int num = wait.size();
		int flag = 0;
		for(int i=0;i<num;i++) {
			int cmd2 = wait.front();
			wait.pop();
			if (!flag) {
				if (cmd2 > 0) {
					flag = setParkInput(cmd2);
					if (flag) continue;
				}
				else {
					flag = setParkOutput(cmd2);
					if (flag) continue;
				}
			}
			wait.push(cmd2);
		}
	}
}
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		solution();
		cout << "#" << t << " " << result << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}