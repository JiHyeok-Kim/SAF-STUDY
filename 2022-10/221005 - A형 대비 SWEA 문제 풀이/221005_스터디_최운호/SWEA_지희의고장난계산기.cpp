#include <iostream>
#include <string.h>
using namespace std;

int btn[10];
int makeNum[1000001];
int tar, answer;

void getAnswer() {
	int num = tar;
	int pushCnt = 0;

	for (int i = tar; i > 1; i--) {
		while (makeNum[i] > 0) {
			if (num % i == 0) {
				pushCnt += 1 + makeNum[i];
				num /= i;
			}
			else break;
		}

		if (num == 1) {
			answer = pushCnt;
			return;
		}
	}

	answer = -1;
}

void make(int num, int pushCnt) {
	if (pushCnt > 7) return;
	if (num > tar) return;

	if (pushCnt > 0) makeNum[num] = pushCnt;

	for (int i = 0; i < 10; i++) {
		if (btn[i]) {
			make(num * 10 + i, pushCnt + 1);
		}
	}
}

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		for (int i = 0; i < 10; i++) {
			cin >> btn[i];
		}
		cin >> tar;

		memset(makeNum, 0, sizeof(int) * 1000001);

		if (tar == 1 && btn[1] == 1) {
			answer = 2;
		}
		else {
			make(0, 0);
			getAnswer();
		}

		cout << "#" << t << " " << answer << '\n';
	}
	return 0;
}