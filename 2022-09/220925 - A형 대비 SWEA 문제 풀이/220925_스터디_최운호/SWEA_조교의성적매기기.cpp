#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct info {
	double score;
	int idx;
};

bool cmp(info A, info B) {
	if (A.score > B.score) return true;
	if (A.score < B.score) return false;

	return false;
}

info score[100];
string result[100];
int n, k;
int credit[10];

string getScore(int a) {
	if (a == 0) return "A+";
	else if (a == 1) return "A0";
	else if (a == 2) return "A-";
	else if (a == 3) return "B+";
	else if (a == 4) return "B0";
	else if (a == 5) return "B-";
	else if(a == 6) return "C+";
	else if (a == 7) return "C0";
	else if (a == 8) return "C-";
	else return "D0";
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			double mid, fi, hw;
			cin >> mid >> fi >> hw;
			double sum = (mid * 0.35) + (fi * 0.45) + (hw * 0.2);
			score[i] = { sum, i };
		}

		sort(score, score + n, cmp);

		for (int i = 0; i < 10; i++) {
			credit[i] = n / 10;
		}

		int idx = 0;
		for (int i = 0; i < n; i++) {
			if (credit[idx] == 0) idx++;
			result[score[i].idx] = getScore(idx);
			credit[idx]--;
		}

		cout << "#" << t << " " << result[k-1] << '\n';
	}
	return 0;
}