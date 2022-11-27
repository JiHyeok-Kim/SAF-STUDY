#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;
long long num[100];

void init() {
	num[0] = 1;
	num[1] = 2;
	for (int a = 2; a <= 90; ++a) {
		num[a] = num[a - 1] + num[a - 2];
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);

	init();
	int T;
	int N;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> N;
		cout << "#" << t << " " << num[N] << " " << num[N - 1] << "\n";
	}
	
	return 0;
}
