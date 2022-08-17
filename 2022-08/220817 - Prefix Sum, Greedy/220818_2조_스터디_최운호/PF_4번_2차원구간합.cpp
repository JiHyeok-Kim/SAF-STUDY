#include <iostream>
using namespace std;

int dx[3] = { -1,0,-1 };
int dy[3] = { 0,-1,-1 };

int arr[1001][1001];
int acc[1001][1001];

int n, m;

int getSum(int y1, int x1, int y2, int x2) {

	int sum = 0;
	sum += acc[y2][x2];
	sum += acc[y1 - 1][x1 - 1];
	sum -= acc[y2][x1 - 1];
	sum -= acc[y1 - 1][x2];

	return sum;
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	acc[0][0] = arr[0][0];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 0 && j == 0) continue;
			int sum = 0;
			for (int k = 0; k < 3; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 1 || nx < 1 || ny > n || nx > n) continue;
				if (k == 2) sum -= acc[ny][nx];
				else sum += acc[ny][nx];
			}
			sum += arr[i][j];
			acc[i][j] = sum;
		}
	}

	for (int i = 0; i < m; i++) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;

		cout << getSum(y1, x1, y2, x2) << '\n';
	}
	return 0;

}