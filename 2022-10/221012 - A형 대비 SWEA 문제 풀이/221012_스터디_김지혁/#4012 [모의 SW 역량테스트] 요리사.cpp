#include <iostream>
using namespace std;

int N, mini, sum;
int map[16][16];
int A[8];
int B[8];
bool used[16];

void init() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}

	return;
}

void getB()
{
	// 4 2 1 3 0 7
	int ida = 0;
	int idb = 0;
	for (int i = 0; i < N; i++) {
		if (A[ida] == i) {
			ida++;
			continue;
		}
		B[idb] = i;
		idb++;
	}

	return;
}

void getAns()
{
	int sumA = 0;
	int sumB = 0;
	for (int i = 0; i < N / 2; i++) {
		for (int j = i + 1; j < N / 2; j++) {
			sumA += map[A[i]][A[j]] + map[A[j]][A[i]];
			sumB += map[B[i]][B[j]] + map[B[j]][B[i]];
		}
	}

	sum = abs(sumA - sumB);
	return;
}

void dfs(int lev, int idx)
{
	if (lev == N / 2) {
		getB();
		getAns();
		if (sum < mini) mini = sum;
		return;
	}

	for (int i = idx; i < N; i++) {
		if (used[i] == true) continue;
		used[i] = true;
		A[lev] = i;

		dfs(lev + 1, i);

		A[lev] = 0;
		used[i] = false;
	}

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		init();

		mini = 9999999;
		dfs(0, 0);
		cout << "#" << tc << " " << mini << "\n";
	}

	return 0;
}