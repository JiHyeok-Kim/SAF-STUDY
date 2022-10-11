#include <iostream>
#include <string>
using namespace std;

int N, M;

string lotto[100];
int reward[100];
long long answer;

int isCorrect(string str) {
	for (int i = 0; i < N; i++) {
		int flag = 1;
		string tmp = lotto[i];
		for (int j = 0; j < 8; j++) {
			if (tmp[j] == '*') continue;
			if (tmp[j] != str[j]) {
				flag = 0;
				break;
			}
		}
		if (flag) return i;
	}

	return -1;
}

int main()
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> N >> M;
		answer = 0;
		for (int i = 0; i < N; i++) {
			cin >> lotto[i] >> reward[i];
		}

		for (int i = 0; i < M; i++) {
			string nums;
			cin >> nums;
			int temp = isCorrect(nums);
			if (temp == -1) continue;
			answer += reward[temp];
		}

		cout << "#" << t << " " << answer << '\n';
	}

	return 0;
}