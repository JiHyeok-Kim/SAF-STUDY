#include<iostream>
using namespace std;
int main() {
	int map[3][5] = {
		1,3,3,5,1,
		3,6,2,4,2,
		1,9,2,6,5
	};
	int n;
	cin >> n;
	int bucket[10] = { 0 };
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 5; x++) {
			int t = map[y][x];
			bucket[t]++;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (bucket[i] == n)
			cout << i << ' ';
	}

	return 0;
}