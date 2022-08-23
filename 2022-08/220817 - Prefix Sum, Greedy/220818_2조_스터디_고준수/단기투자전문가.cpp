#include<iostream>
#include<vector>
#include<queue>



using namespace std;
string word[11];
string res_str = "";
int flag = 0;


void init() {
	res_str = "";
	flag = 0;
}

int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> word[i];
		for (int j = 0; j < word[i][j]; j++)
		{
			if (word[i][j] != '[' && flag == 0) continue;
			if (word[i][j] == '[')
			{
				flag++;
				continue;
			}
			if (flag == 1 && word[i][j] >= 48 && word[i][j] <= 57)
			{
				res_str += word[i][j];
			}
			if (word[i][j] == ']' && res_str.size() == 5)
			{
				cout << '[' << res_str << ']' << '\n';
				init();
			}

		}
		init();
	}



}