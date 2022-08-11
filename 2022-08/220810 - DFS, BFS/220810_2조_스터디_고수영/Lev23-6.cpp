#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string s;
char path[100] = {};
int cnt = 0;

void run(int lev)
{
	if (lev == 4)
	{
		cnt++;
		return;
	}
	for (int i = 0; i < 5; i++)
	{
		path[lev] = s[i];

		if (lev > 0 && ((int(path[lev]) - int(path[lev - 1])) > 3))continue;
		else if (lev > 0 && ((int(path[lev]) - int(path[lev - 1])) < -3))continue;
		run(lev + 1);
		path[lev] = 0;
	}
}

int main()
{
	cin >> s;
	run(0);
	cout << cnt;
	
}