#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

string word1="";
string word2="";
int cnt = 1;
int flag = 0;
int main()
{
	int tc;
	cin >> tc;
	for (int testcase = 0; testcase < tc; testcase++)
	{
		string word;
		cin >> word;
		word1 = "";
		word2 = "";
		for (int i = 0; i < 10; i++)
		{
			word1 += word[i];
			word2 = "";
			for (int j =i+1; j <i+1+cnt; j++)
			{
				word2 += word[j];
			}
			if (word1==word2)
			{
				flag++;
				break;
				
			}
			cnt++;
		}
		if(flag==1)
		{ 
		cout << '#' << testcase + 1 << ' ' << word1.size() << '\n';
		flag = 0;
		cnt = 1;
		}
	}



	return 0;
}