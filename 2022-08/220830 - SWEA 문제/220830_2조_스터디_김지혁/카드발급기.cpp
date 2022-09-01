#include <iostream>
using namespace std;
int Arr[1000001] = { 0 };
int dat[1000001] = { 0 };
int num[1000001] = { 0 };

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int tc;
	cin >> tc;
	int number;
	for (int i = 0; i < tc; i++) {
		cin >> number;
		int flag = 0;
		for (int i = 0; i < number; i++) {
			cin >> Arr[i];
		}
		for (int i = 0; i < number; i++) {
			cin >> num[i];
		}
		for (int i = 0; i < number; i++) {
			dat[num[i]]= Arr[i];
		}

		for (int i = 1; i < number; i++) {
			if (dat[i] < dat[i + 1]) {
				flag = 1;
			}
		}
		if (flag == 1) {

			cout << "NO" << '\n';
		}
		else {
			cout << "YES" << '\n';
		}
	}

	return 0;
}