#include <iostream>
using namespace std;

bool canUse[100000];

int G, P;

int main() {
	cin >> G >> P;

	int answer = 0;

	for (int i = 0; i < P; i++) {
		int ver;
		cin >> ver;
		int flag = 1;
		for (int j = ver; j >= 1; j--) {
			if (canUse[j] == false) {
				canUse[j] = true;
				answer++;
				flag = 0;
				break;
			}
		}
		if (flag) break;
	}

	cout << answer;

	return 0;
}