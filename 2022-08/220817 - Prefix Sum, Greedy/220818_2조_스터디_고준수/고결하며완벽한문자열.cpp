#include<iostream>
#include<vector>
#include<queue>



using namespace std;




int flag_srt = 0;
int used[100] = { 0 };
string str[101];



void init() {
	for (int i = 0; i < 100; i++)
	{
		used[i] = 0;
	}

}

int hakin(string  str)
{
	for (int j = 0; j < str.size(); j++)
	{
		if (str[j] != '<' && flag_srt == 0)
		{
			continue;
		}

		if (str[j] == '<')
		{
			flag_srt = 0;
			flag_srt++;
			continue;

		}
		if (str[j] == '>')
		{
			flag_srt = 0;
			init();
			continue;
		}
		if (flag_srt == 1)
		{
			used[int(str[j])]++;
			if (used[int(str[j])] == 2)
			{
				init();
				return 0;
			}

		}



	}
	return 1;

}





int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> str[i];
		if (hakin(str[i]) == 1)
		{
			cout << 'O';

		}
		else if (hakin(str[i]) == 0)
		{

			cout << 'X';
		}
	}


}