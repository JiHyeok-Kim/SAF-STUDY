#include <iostream>
#include <cstring>
#include <string>

using namespace std;

char name[4] = {};
char path[10] = {};
int used[4] = { 0 };

void run(int lev)
{
	if (lev == 3)
	{
		cout << path << "\n";
		return;
	}
	for (int a = 0; a < 4; a++)
	{
		if (used[a] == 1)continue;
		used[a] = 1;
		path[lev] = name[a];
		run(lev + 1);
		path[lev] = 0;
		used[a] = 0;
	}
}

int main()
{	
	cin >> name;
	run(0);


}