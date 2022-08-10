#include <iostream>
#include <string>
using namespace std;

string name;
char path[10];
int via[10];

void run(int level)
{
	if (level == 3)
	{
		cout << path << endl;
		return;
	}

	for (int x = 0; x < 4; x++)
	{
		if (via[x] == 0)
		{
			via[x] = 1;
			path[level] = name[x];
			run(level + 1);
			path[level] = 0;
			via[x] = 0;
		}
	}
}

int main()
{
	cin >> name;

	run(0);

	return 0;
}