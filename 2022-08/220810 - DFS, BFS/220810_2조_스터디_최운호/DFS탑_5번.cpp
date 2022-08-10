#include <iostream>
using namespace std;

int n;
int answer;

int nums[3] = { 1,2,3 };

void dfs(int now) {
	if (now >= n) {
		if (now == n) answer++;
		return;
	}
	for (int i = 0; i < 3; i++) {
		dfs(now + nums[i]);
	}
}

int main() {
	cin >> n;

	dfs(0);

	cout << answer;
	return 0;
}