#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string ABC = "ABC";
int n;
int cnt = 0;
char path[100] = {};

void run(int lev)
{
	if (lev == n)
	{
		cnt++;
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		path[lev] = ABC[i];
		if (lev >= 2 && (path[lev] == path[lev - 1]) && (path[lev - 1] == path[lev - 2]))continue;
		run(lev + 1);
		path[lev] = 0;
	}
}

int main()
{
	cin >> n;
	run(0);
	cout << cnt;
	
}