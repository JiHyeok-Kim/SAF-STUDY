#include <iostream>
using namespace std;

int n;
int ret;

void DFS(int cnt, int sum) {
	if (sum > n) return;
	if (sum == n) {
		ret++;
		return;
	}

	for (int i = 1; i <= 3; ++i) {
		DFS(cnt + 1, sum + i);
	}
}

int main()
{
	cin >> n;
	DFS(0, 0);
	cout << ret;
	return 0;
}