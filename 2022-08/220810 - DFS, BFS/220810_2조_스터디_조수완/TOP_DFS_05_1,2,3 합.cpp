#include <iostream>
using namespace std;

int target, cnt;

void DFS(int lev, int sum) {
	if (sum == target) cnt++;
	if (lev == target) return;

	for (int b = 1; b <= 3; b++) {
		DFS(lev + 1, sum + b);
	}
}

int main() {
	cin >> target;
	DFS(0, 0);
	cout << cnt;

	return 0;
}