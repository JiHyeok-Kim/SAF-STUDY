#include <iostream>
using namespace std;
int dat[101] = { 0 };
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int Type;
	cin >> Type;
	if (Type == 2) {
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			dat[temp]++;
		}
		for (int i = 0; i < 101; i++) {
			if (dat[i] > 1) {
				cout << "중복발견";
				return 0;
			}
		}
		cout << "중복없음";
		return 0;
	}
	else if (Type == 1) {
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			dat[temp]++;
		}
		for (int i = 1; i < 10; i++) {
			cout << i << ":" << dat[i] << "개"<<'\n';
		}
	}


	return 0;
}