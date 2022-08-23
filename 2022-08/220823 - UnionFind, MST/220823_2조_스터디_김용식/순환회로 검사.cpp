#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int flag = 0;
int Arr[1001][1001];
int parent[100];

int Find(int now) {
	if (parent[now] == now) return now;
	int ret = Find(parent[now]);
	parent[now] = ret;
	return ret;
}


void Union(int A, int B) {
	
	int pA = Find(A);
	int pB = Find(B);
	if (pA == pB) {
		flag = 1;
		return;
	}
	parent[pB] = pA;
}



int main() {
	//FILE* freinput = freopen("input.txt","rt",stdin);
	for (int i = 0; i < 100; i++) {
		parent[i] = i;
	}
	
	int N; 
	cin >> N;
	
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < N; j++) {
			cin >> Arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (Arr[i][j] == 1) {
				Union(i, j);
			}
		}
	}


	if (flag == 1) {
		cout << "WARNING";
	}
	else {
		cout << "STABLE";
	}

	return 0;
}