#include <iostream>
#include <algorithm>
using namespace std;

long long N, list[110000];
long long p1, p2, minVal = 21e8;

void getAns(int s, int e) {
	while (s < e) {
		int sum = list[e] + list[s];
		if (sum == 0) {
			p1 = list[s];
			p2 = list[e];
			return;
		}
		if (abs(sum) < minVal) {
			minVal = abs(sum);
			p1 = list[s];
			p2 = list[e];
		}
		if (sum < 0) s++;
		if (sum > 0) e--;
	}
	return;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> list[i];
	sort(list, list + N);
	getAns(0, N - 1);
	cout << p1 << " " << p2;
	return 0;
}