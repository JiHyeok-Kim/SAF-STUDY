#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

char parent[100] = {0};
int dat[200] = { 0 };
int groupCnt=0;
int perCnt=0;
char Find(char now) {
	if (parent[now] == 0) return now;
	char ret = Find(parent[now]);
	parent[now] = ret;
	return ret;
}


void Union(char A, char B) {
	int pA = Find(A);
	int pB = Find(B);
	if (pA == pB)return;
	parent[pB] = pA;
	groupCnt++;
	
	if (dat[A] == 0) perCnt++;
	if (dat[B] == 0)perCnt++;
	dat[A] = 1;
	dat[B] = 1;

}

int main() {
	//FILE* freinput = freopen("input.txt", "rt", stdin);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char from, to;
		cin >> from >> to;
		Union(from,to);
	}

	cout << perCnt - groupCnt << '\n';
	cout << 26 - perCnt;
	return 0;
}