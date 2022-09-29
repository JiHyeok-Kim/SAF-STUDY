#include <iostream>
using namespace std;

int N, K;
int Arr[16][16] = { 0 };
int dat[16][16] = { 0 };

int FindX() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dat[i][j] = Arr[i][j];
		}
	}

	int ret = 0;

	
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (dat[i][j] == 0)continue;
				if (dat[i][j] == 1) {
					int now = i;
					int next = j;
					int consume = 0;
					while (1) {
						if (dat[now][next] == 0 || now == N) break;
						dat[now][next] = 0;
						now++;
						consume++;
					}
					if (consume == K) ret++;
				}
			}
		}
	
	return ret;
}


int FindY() {
	// 복사배열 한개 만듦

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dat[i][j] = Arr[i][j];
		}
	}

	int ret = 0;

	
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (dat[i][j] == 0)continue;
				if (dat[i][j] == 1) {
					int now = i;
					int next = j;
					int consume = 0;
					while (1) {
						if (dat[now][next] == 0 || next == N) break;
						dat[now][next] = 0;
						next++;
						consume++;
					}
					if (consume == K) ret++;
				}
			}
		}

	

	return ret;
}


void input() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Arr[i][j];
		}
	}
	return;
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int Tc;
	cin >> Tc;
	for (int tc = 1; tc <= Tc; tc++) {
		
		cin >> N >> K;
		input();
		int retY = FindY();
		int retX = FindX();

		cout << "#" << tc << " " << retX + retY << '\n';
	}




	return 0;
}