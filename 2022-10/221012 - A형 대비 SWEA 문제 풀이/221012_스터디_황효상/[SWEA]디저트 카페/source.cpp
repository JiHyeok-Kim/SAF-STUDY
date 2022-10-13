#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

struct Node {
	int x;
	int y;
};

int T, N;

int map[21][21];

int check[101];
int sX, sY;
int maxi = -21e8;

void toZero(int x, int y, int r_count, int l_count, int store) {
	int nx = x - 1;
	int ny = y + 1;
	if (nx < 0 || nx >= N || ny < 0 || ny >= N) return;

	if (nx == sX && ny == sY) {
		if (store > maxi)
			maxi = store;
		return;
	}

	if (!check[map[nx][ny]] ) {
		l_count -= 1;
		store += 1;
		check[map[nx][ny]] = 1;
		toZero(nx, ny, r_count, l_count, store);
		check[map[nx][ny]] = 0;
	}

}


void toNine(int x, int y, int r_count, int l_count, int store) {
	int nx = x - 1;
	int ny = y - 1;
	if (nx < 0 || nx >= N || ny < 0 || ny >= N) return;
	if (check[map[nx][ny]]) return;

	r_count -= 1;
	store += 1;
	check[map[nx][ny]] = 1;
	if (r_count == 0) {
		toZero(nx, ny, r_count, l_count, store);
	}
	else {
		toNine(nx, ny, r_count, l_count, store);
	}
	check[map[nx][ny]] = 0;
}


void toSix(int x, int y, int r_count, int l_count, int store) {
	int nx = x + 1;
	int ny = y - 1;
	if (nx < 0 || nx >= N || ny < 0 || ny >= N) return;
	if (check[map[nx][ny]]) return;

	l_count += 1;
	store += 1;
	check[map[nx][ny]] = 1;
	toNine(nx, ny, r_count, l_count, store);
	toSix(nx, ny, r_count, l_count, store);
	check[map[nx][ny]] = 0;
}


void toThree(int x, int y, int r_count, int l_count, int store) {
	int nx = x + 1;
	int ny = y + 1;
	if (nx < 0 || nx >= N || ny < 0 || ny >= N) return;
	if (check[map[nx][ny]]) return;

	check[map[nx][ny]] = 1;
	r_count++;
	store += 1;
	toSix(nx, ny, r_count, l_count, store);
	toThree(nx, ny, r_count, l_count, store);

	check[map[nx][ny]] = 0;
}


void desert(int x, int y) {
	check[map[x][y]] = 1;
	sX = x;
	sY = y;
	toThree(x, y, 0, 0, 1);
	check[map[x][y]] = 0;

}
void solve() {
	for (int a = 0; a < N-2; ++a) {
		for (int b = 1; b < N - 1; ++b) {
			desert(a, b);
		}
	}

}
void input() {
	cin >> T;

	for (int t = 0; t < T; ++t) {
		cin >> N; 
		for (int a = 0; a < N; ++a) {
			for (int b = 0; b < N; ++b) {
				cin >> map[a][b];
			}
		}
		solve();
		cout << "#" << t + 1 << " ";
		if (maxi == -21e8)
			cout << -1 << "\n";
		else
			cout << maxi << "\n";
		maxi = -21e8;
	}
}

int main()
{
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
	cout << maxi;
	return 0;

}
