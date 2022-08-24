#include <iostream>
using namespace std;
int Arr[4] = { 500,100,50,10 };
int main() {
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		cnt += (n / Arr[i]);
		n = n % Arr[i];
	}
	cout << cnt;
	return 0;
}