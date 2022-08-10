#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> alist(1001);
int N;
int ptn1[1001], ptn2[1001], ptn3[1001];
int used1[1001], used2[1001], used3[1001];
int idx1, idx2, idx3;
void PTN1(int now) {
	for (int i = 0; i < alist[now].size(); i++) {
		if (i == 1) {
			ptn1[idx1] = now;
			idx1++;
		}
		int next = alist[now][i];
		if (next == -1) continue;
		if (used1[next] == 1) continue;
		used1[next] = 1;
		PTN1(next);
	}
}
void PTN2(int now) {
	ptn2[idx2] = now;
	idx2++;
	for (int i = 0; i < alist[now].size(); i++) {
		int next = alist[now][i];
		if (next == -1) continue;
		if (used2[next] == 1) continue;
		used2[next] = 1;
		PTN2(next);
	}
}
void PTN3(int now) {
	for (int i = 0; i < alist[now].size(); i++) {
		int next = alist[now][i];
		if (next == -1) continue;
		if (used3[next] == 1) continue;
		used3[next] = 1;
		PTN3(next);
	}
	ptn3[idx3] = now;
	idx3++;
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int from, lto, rto;
		cin >> from >> lto >> rto;
		alist[from].push_back(lto);
		alist[from].push_back(rto);
	}
	used1[1] = 1;
	used2[1] = 1;
	used3[1] = 1;
	PTN1(1);
	PTN2(1);
	PTN3(1);
	for (int i = 0; i < N; i++) cout << ptn1[i] << " ";
	cout << '\n';
	for (int i = 0; i < N; i++) cout << ptn2[i] << " ";
	cout << '\n';
	for (int i = 0; i < N; i++) cout << ptn3[i] << " ";

	return 0;
}