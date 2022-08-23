#include <iostream>
using namespace std;

struct Node {
	char y;
	char x;
};

int line[123];
int bucket[123];
int N;
int cnt;

int findBoss(char tar)
{
	if (line[tar] == 0) return tar;

	int ret = findBoss(line[tar]);
	line[tar] = ret;

	return ret;
}

void unionGroup(char a, char b)
{
	char t1 = findBoss(a);
	char t2 = findBoss(b);
	if (t1 == t2) return;

	line[t2] = t1;
	cnt++;

	return;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	int teamAns = 0;
	int soloAns = 0;
	for (int i = 0; i < N; i++)
	{
		char a, b;
		cin >> a >> b;
		bucket[a] = 1;
		bucket[b] = 1;
		unionGroup(a, b);
	}

	char ch2 = 'A';
	for (int i = ch2; i <= 'Z'; i++)
	{
		if (bucket[i] == 1) {
			teamAns++;
			continue;
		}
		soloAns++;
	}
	teamAns -= cnt;
	cout << teamAns << "\n" << soloAns;

	return 0;
}