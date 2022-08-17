#include <iostream>
using namespace std;
int n;
int line[110000];
int acc[110000];
int maxi = -21e8;

int getSum(int a, int b) {
	if (a > b) return 0;
	if (a == 0) return acc[b];
	return acc[b] - acc[a - 1];
}

int maxe(int a, int b) {
	if (a < b) {
		return b;
	}
	else return a;
}

int main() {

	//freopen_s(new FILE*, "input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	//입력받고, 부분합 세팅
	for (int i = 0; i < n; i++) cin >> line[i];
	acc[0] = line[0];
	for (int i = 1; i < n; i++) {
		acc[i] = acc[i - 1] + line[i];
	}
	//맨 오른쪽 : 바구니
	//맨 왼쪽 : 코코
	//중간(i) : 민철

	for (int i = 1; i < n - 1; i++) {
		int ga = getSum(1, n - 1); //코코 ~ 바구니
		int gb = getSum(i + 1, n - 1); //민철 ~ 바구니
		maxi = maxe(maxi, ga + gb - line[i]);
	}
	//맨 왼쪽 : 바구니
	//맨 오른쪽 : 민철
	//중간(i) : 코코
	for (int i = 1; i < n - 1; i++) {
		int ga = getSum(0, n - 2);
		int gb = getSum(0, i - 1);
		maxi = maxe(maxi, ga + gb - line[i]);
	}
	//바구니 : 중간
	//맨 왼쪽, 오른쪽 : 민철, 코코
	for (int i = 1; i < n - 1; i++) {
		int ga = getSum(1, i);
		int gb = getSum(i, n - 2);
		maxi = maxe(maxi, ga + gb);
	}

	cout << maxi;
	return 0;
}