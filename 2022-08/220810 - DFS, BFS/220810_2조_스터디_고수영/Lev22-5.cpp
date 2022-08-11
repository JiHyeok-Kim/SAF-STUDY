#include <iostream>
#include <cstring>

using namespace std;
int n;
int path[6] = {};
void run(int lev)
{
	if (lev == 4)
	{
		for (int a = 0; a < 4; a++)
		{
			cout << path[a];
		}
		cout<< "\n";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		path[lev] = i + 1;
		run(lev + 1);
		path[lev] = 0;
	}
}

int main()
{	
	cin>>n;
	run(0);
}