#include <iostream>
using namespace std;

int dx[4] = {- 1,1,0,0};
int dy[4] = { 0,0,1,-1 };
int Arr[11][11] = { 0 };
int N;

int isGoal(int y, int x) {
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!(Arr[y][x] == 1))return 1;
	}
	return 0;
}

void clear() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Arr[i][j] = 0;
		}
	}
	return;

}


int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int tc;
	cin >> tc;

	int bigo = 0;
	int x=0, y=0;
	for (int i = 1; i <= tc; i++) {
		int ret = 1;
		cin >> N;
		while (1) {
			int find = isGoal(y,x);
			if (find == 0)break;

			for (int i = 0; i< N; i++) {
				if (i == N || Arr[y][i] != 0)continue;
				Arr[y][i] = ret++;
				bigo = i;
			}
			x = bigo;
			bigo = 0;
			for (int i = 0; i < N; i++) {
				if (Arr[i][x] != 0)continue;
				Arr[i][x] = ret++;
				bigo = i;
			}
			y = bigo;
			bigo = 0;
			for (int i = N - 1; i >= 0; i--) {
				if (Arr[y][i] != 0)continue;
				Arr[y][i] = ret++;
				bigo = i;
			}
			x = bigo;
			bigo = 0;
			for (int i = N - 1; i >= 0; i--) {
				if (Arr[i][x] != 0)continue;
				Arr[i][x] = ret++;
				bigo = i;
			}
			y = bigo;
			bigo = 0;
		}
		cout << "#" << i<<'\n';

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << Arr[i][j] << " ";
			}cout << '\n';
		}
		clear();
	}



	return 0;
}