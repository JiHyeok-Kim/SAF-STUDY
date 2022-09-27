#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int turn;
string val;
string ideal;
int answer;

void change(int a, int b) {
	char ch = ideal[a];
	ideal[a] = ideal[b];
	ideal[b] = ch;
}
void change2(int a, int b) {
	char ch = val[a];
	val[a] = val[b];
	val[b] = ch;
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> val >> turn;
		ideal = val;
		sort(ideal.begin(), ideal.end(), greater<>());

		int len = val.size();


		int cnt = 0;
		int dat[10] = { 0 };
		int flag = 0;
		for (int i = 0; i < len; i++) {
			int num = val[i] - '0';
			dat[num]++;
			if (dat[num] > 1) flag = 1;
			if (val[i] != ideal[i]) cnt++;
		}

		int idealT;
		if (cnt % 2 == 0) idealT = cnt / 2;
		else idealT = cnt / 2 + 1;
		answer = 0;

		if (idealT == turn) answer = stoi(ideal);
		else {
			if (idealT > turn) {
				int idx = 0;

				while (turn > 0) {
					int maxVal = 0;
					int maxIdx = 0;
					for (int i = len - 1; i >= idx; i--) {
						int nn = val[i];
						if (nn > maxVal) {
							maxVal = nn;
							maxIdx = i;
						}
					}
					if (idx == maxIdx) {
						idx++;
						continue;
					}
					change2(maxIdx, idx);
					idx++;
					turn--;
				}
				answer = stoi(val);
			}
			else {
				int remain = turn - idealT;
				if (remain % 2 == 0) answer = stoi(ideal);
				else {
					if (flag) answer = stoi(ideal);
					else {
						change(len - 1, len - 2);
						answer = stoi(ideal);
					}
				}
			}
		}

		cout << "#" << t << " " << answer << '\n';
	}
	return 0;
}