#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string s = "EWABC";
char c;
char path[100] = {};
int used[10] = { 0 };

void run(int lev)
{
	if(lev == 4)
	{
		cout << path << '\n';
		return;
	}

	for (int i = 0; i < 5; i++)
	{
		if (used[i] == 1)continue;
		used[i] = 1;
		path[lev] = s[i];
		if (path[lev] == c)continue;
		run(lev + 1);
		path[lev] = 0;
		used[i] = 0;
	}
}

int main()
{
	cin >> c;
	run(0);
	
}