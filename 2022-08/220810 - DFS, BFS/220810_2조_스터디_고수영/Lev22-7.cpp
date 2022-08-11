#include <iostream>
#include <cstring>
#include <string>

using namespace std;
string code = "ABCD";
string s;
int cnt = 0;

void run(int lev,string sum)
{
	if (lev == 3)
	{
		cnt++;
		if (s == sum)
		{
			cout << cnt << "번째";
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		run(lev + 1, sum + code[i]);
	}
}

int main()
{
	
	cin >> s;

	run(0,"");
}