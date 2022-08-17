#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>

using namespace std;

int arr[1002][1002], acc[1002][1002];

int main() {
	int y1, y2, x1, x2;
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			acc[i][j] = acc[i - 1][j] + acc[i][j - 1] + arr[i][j] - acc[i - 1][j - 1];
		}
	}

	for (int i = 1; i <= M; i++) {

		cin >> y1 >> x1 >> y2 >> x2;
		cout << acc[y2][x2] - acc[y2][x1 - 1] - acc[y1 - 1][x2] + acc[y1 - 1][x1 - 1] << endl;
	}

	return 0;
}