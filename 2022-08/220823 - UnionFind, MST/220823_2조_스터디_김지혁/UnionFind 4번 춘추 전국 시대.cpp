#include <iostream>
#include <string>
using namespace std;

char line[123];
int country[123];
int N;
int T;
int ans;

char findBoss(char tar)
{
	if (line[tar] == '\0') return tar;

	char ret = findBoss(line[tar]);
	line[tar] = ret;
	return ret;
}

void unionGroup(char a, char b)
{
	char t1 = findBoss(a);
	char t2 = findBoss(b);
	if (t1 == t2) return;

	line[t2] = t1;
	country[t1] += country[t2];
	return;
}

int main()
{
	//freopen_s(new FILE*, "test.txt", "r", stdin);
	cin >> N;
	char ch = 'A';
	for (int i = 0; i < N; i++)
	{
		cin >> country[ch];
		ch++;
	}
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		char a, b;
		string str;
		cin >> str;
		if (str == "alliance")
		{
			cin >> a >> b;
			unionGroup(a, b);
		}
		if (str == "war")
		{
			cin >> a >> b;
			int temp = country[findBoss(a)];
			country[findBoss(a)] -= country[findBoss(b)];
			country[findBoss(b)] -= temp;
		}
	}
	ch = 'A';
	for (int i = 0; i < N; i++)
	{
		if (country[findBoss(ch)] > 0) ans++;
		ch++;
	}
	cout << ans;

	return 0;
}