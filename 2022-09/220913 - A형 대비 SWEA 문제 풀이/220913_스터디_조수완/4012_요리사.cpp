#include <iostream>
#include <cmath>
using namespace std;

int ans, N, arr[20][20];
int path1[10], path2[10], path[20];
int used[20];
int used1[10], used2[10];
int sum1, sum2;

void init() {
	ans = 21e8;
	for (int i = 0; i < 20; i++)
		used[i] = 0;
}
void init2() {
	for (int i = 0; i < 10; i++) {
		used1[i] = 0;
		used2[i] = 0;
	}
	sum1 = 0;
	sum2 = 0;
}
void food1(int lev,int start) {
	if (lev == 2) {
		sum1 += arr[path1[0]][path1[1]];
		sum1 += arr[path1[1]][path1[0]];
		return;
	}
	for (int i = start; i < N; i++) {
		if (used[i] == 0) continue;
		path1[lev] = i;
		food1(lev + 1,i+1);
	}
}
void food2(int lev,int start) {
	if (lev == 2) {
		sum2 += arr[path2[0]][path2[1]];
		sum2 += arr[path2[1]][path2[0]];
		return;
	}
	for (int i = start; i < N; i++) {
		if (used[i] == 1) continue;
		path2[lev] = i;
		food2(lev + 1, i + 1);
	}
}

void sol(int lev,int start) {
	if (lev == N/2) {
		init2();
		food1(0,0);
		food2(0,0);
		int temp = abs(sum1 - sum2);
		ans = min(ans, temp);
		return;
	}

	for (int b = start; b < N; b++) {
		used[b] = 1;
		path[lev] = b;
		sol(lev + 1, b + 1);
		used[b] = 0;
	}

}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		cin >> N;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				cin >> arr[y][x];
			}
		}
		sol(0,0);
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}