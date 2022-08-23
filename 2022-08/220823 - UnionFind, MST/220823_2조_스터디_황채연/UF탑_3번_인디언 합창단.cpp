#include <iostream>
using namespace std;

int n, group_cnt, total = 26;
int parent[30];
int group_dat[30];

void init() {
	for (int i = 0; i < 30; ++i) {
		parent[i] = i;
	}
}

int Find(int tar) {
	if (parent[tar] == tar) return tar;
	int ret = Find(parent[tar]);
	parent[tar] = ret;
	return ret;
}

void Union(int A, int B) {
	if (group_dat[A] == 0) {
		group_dat[A] = 1;
		group_cnt++;
		total--;
	}
	if (group_dat[B] == 0) {
		group_dat[B] = 1;
		group_cnt++;
		total--;
	}

	int pA = Find(A);
	int pB = Find(B);
	if (pA == pB) return;
	parent[pB] = pA;
	group_cnt--;
}

int main()
{
	init();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char target1, target2;
		cin >> target1 >> target2;
		Union(target1 - 'A', target2 - 'A');
	}
	
	cout << group_cnt << "\n" << total;
	return 0;
}