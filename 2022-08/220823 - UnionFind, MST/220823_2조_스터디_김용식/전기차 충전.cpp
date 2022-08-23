#include <iostream>
using namespace std;


int charger[100001] = {0};
int carNum[100001] = {0};

int Find(int now) {
	if (carNum[now] == -1) return now;
	return carNum[now] = Find(carNum[now]);
}

void Union(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);
	if (pA == pB)return;
	carNum[pB] = pA;
}


int main() {

	//freopen_s(new FILE *, "input.txt", "r", stdin);
	
	int N,M;
	cin >> N >> M;
	
	for (int i = 0; i < 100001; i++) {
		carNum[i] = -1;
	}

	for (int i = 0; i < M; i++) {
		cin >> charger[i];
	}
	int cnt = 0;

	for (int i = 0; i < M; i++) {
		int car = charger[i];

		int n = Find(car);
		if (n == 0) break;

		Union(n - 1, n);
		cnt++;
	}
	cout << cnt;


	return 0;
}