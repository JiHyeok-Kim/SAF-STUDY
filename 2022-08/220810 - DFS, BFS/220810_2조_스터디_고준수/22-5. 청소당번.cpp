#include<iostream>
using namespace std;

int n;
int path[10];

void run(int level)
{
	if (level == 4)
	{
		for (int i = 1; i <= level; i++)
		{
			cout << path[i];
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		path[level + 1] = i + 1;
		run(level + 1);
		path[level + 1] = 0;
	}
}
int main()
{
	cin >> n;
	run(0);
}