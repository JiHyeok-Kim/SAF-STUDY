#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

string input[5];
string str = "MCDMCDMCDMCD";
int main()
{
	for (int i = 0; i < 5; i++)
	{
		cin >> input[i];
	}
	int str_cnt = 0;
	for (int i = 0; i < 5; i++)
	{
		int ret = 0;
		int cnt = 0;

		while (ret != -1 && cnt < input[i].size())
		{
			ret = input[i].find("MCD", cnt);
			if (ret != -1)
			{
				str_cnt++;
			}

			if (ret >= 0)
			{
				cnt = ret + 3;
			}
		}
	}

	cout << str_cnt;


}