#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N, M, order = 1;
int cnt, used[130], checkP[130], sortArr[200];
vector<vector<char>> alist(1001);
string str[1001];

void DFS(char now) {
	for (int i = 0; i < alist[now].size(); i++) {
		int next = alist[now][i];
		if (next == '#') continue;
		if (used[next] == 1) continue;
		used[next] = 1;
		sortArr[next] = order;
		order++;
		DFS(next);
	}
}
char getParent() {
	for (int i = 'a'; i <= 'z'; i++) {
		if (checkP[i] == 2) return (char)i;
	}
}
int sort(string str1, string str2) {
	if (str1.size() <= str2.size()) {
		for (int i = 0; i < str1.size(); i++) {
			if (sortArr[str1[i]] < sortArr[str2[i]]) return 1;
			else if (sortArr[str1[i]] > sortArr[str2[i]]) return 0;
		}
		return 1;
	}
	else {
		for (int i = 0; i < str2.size(); i++) {
			if (sortArr[str1[i]] < sortArr[str2[i]]) return 1;
			else if (sortArr[str1[i]] > sortArr[str2[i]]) return 0;
		}
		return 0;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		char P, L, R;
		cin >> P >> L >> R;
		alist[P].push_back(L);
		alist[P].push_back(R);
		checkP[P]+=2;
		checkP[L]++;
		checkP[R]++;
	}
	cin >> M;
	for (int i = 0; i < M; i++) cin >> str[i];
	char sNode = getParent();
	used[sNode] = 1;
	DFS(sNode);

	for (int j = 1; j < M; j++) {
		for (int i = 1; i < M - j + 1; i++) {
			if (!sort(str[i - 1], str[i])) swap(str[i - 1], str[i]);
		}
	}

	for (int i = 0; i < M; i++) cout << str[i] << '\n';

	return 0;
}