#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

char Arr[6] = {"_____"};

int main() {
	//FILE* freinput = freopen("input.txt", "rt", stdin );
	int idx, life;
	cin >> idx >> life;
	int ans;
	while (1) {
		ans = 0;
		for (int i = 0; i < 5; i++) {
			if (i == idx && life != 0) {
				cout << life;
				ans = 1;
				continue;
			}
			cout << Arr[i];
		}
		life--;
		idx++;

		cout << '\n';
		
		if (ans == 0) {
			return 0;
		}
	
	}
	


	return 0;
}