#include <iostream>
#include <cstring>

using namespace std;

char arr[4] = { 'B','G','T','K' };
int n;
char path[10] = {};

void run(int lev)
{
	if (lev == n)
	{
		cout << path << endl;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		path[lev] =  arr[i];
		run(lev + 1);
		path[lev]=  0;
	}

}


int main()
{	
	cin >> n;
	run(0);
}