#include <iostream>
#include <string>
using namespace std;

int N, T;
int group_people[30];
int group_cnt[30];
int parent[30];
int total;

void init() {
	for (int i = 0; i < 30; ++i) {
		parent[i] = i;
		group_cnt[i] = 1;
	}
}

int Find(int tar) {
	if (parent[tar] == tar) return tar;
	int ret = Find(parent[tar]);
	parent[tar] = ret;
	return ret;
}

void Union(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);
	if (pA == pB) return;
	parent[pB] = pA;
	group_people[pA] += group_people[pB];
	group_people[pB] = 0;
	group_cnt[pA] += group_cnt[pB];
	group_cnt[pB] = 0;
}

void War(int A, int B) {
	int groupA = group_people[Find(A)];
	int groupB = group_people[Find(B)];
	if (groupA < groupB) {
		total -= group_cnt[Find(A)];
		group_people[Find(A)] = 0;
		group_cnt[Find(A)] = 0;
	}
	if (groupA > groupB) {
		total -= group_cnt[Find(B)];
		group_people[Find(B)] = 0;
		group_cnt[Find(B)] = 0;
	}
	if (groupA == groupB) {
		total -= (group_cnt[Find(A)] + group_cnt[Find(B)]);
		group_people[Find(A)] = 0;
		group_cnt[Find(A)] = 0;
		group_people[Find(B)] = 0;
		group_cnt[Find(B)] = 0;
	}
}

int main()
{
	init();
	cin >> N;
	total = N;
	for (int i = 0; i < N; ++i) {
		cin >> group_people[i];
	}

	cin >> T;
	for (int i = 0; i < T; ++i) {
		string in;
		char target1, target2;
		cin >> in >> target1 >> target2;
		if (in == "alliance") {
			Union(target1 - 'A', target2 - 'A');
		}
		if (in == "war") {
			War(target1 - 'A', target2 - 'A');
		}
	}

	cout << total;
	return 0;
}