#include<iostream>
using namespace std;

char path[10];
char name[10] = "BGTK";
int n;

void run(int level)
{
	if (level == n)
	{
		cout << path << endl;
		return;
	}

	for (int x = 0; x < 4; x++)
	{
		path[level] = name[x];
		run(level + 1);
		path[level] = 0;
	}

}

int main()
{
	cin >> n;
	run(0);

	return 0;
}