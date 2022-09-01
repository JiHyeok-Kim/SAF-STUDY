#include <iostream>
using namespace std;
int Arr[1001][1001] = { 0 };
int N;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Arr[i][j];
		}
	}
	return;
}

void boom(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || nx >= N || ny >= N)continue;
		Arr[ny][nx] = 0;
		Arr[y][x] = 0;
	}
	return;
}

int find() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Arr[i][j] != 0) {
				return 0;
			}
		}
	}
	return -1;
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	int A = 1;
	int ans = 0;
	int real=0;
	while (1) {
		if (real == -1) { break; }
		for (int i = 0; i < N; i++) {
			int flag = 0;
			for (int j = 0; j < N; j++) {
				if (Arr[i][j] == A) {
					boom(i, j);
					flag = 1;
					break;
				}
			}
			if (flag == 1) {
				break;
			}
		}
		A++;
		ans++;

		real = find();
		
	}
	
	cout << ans<<"ÃÊ";
	return 0;
}