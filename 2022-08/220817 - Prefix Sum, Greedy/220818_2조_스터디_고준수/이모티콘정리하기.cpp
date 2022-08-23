#include<iostream>
#include<vector>
#include<queue>



using namespace std;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	string word;
	cin >> word;
	word += "@@@@@@";

	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] == '(' && word[i + 1] == '(')
		{
			word[i] = '0';
		}
		if (word[i] == ')' && word[i + 1] == ')')
		{
			word[i] = '0';
		}

		if (word[i] == '^' && word[i + 1] == '^' && word[i + 2] == '^')
		{
			word[i + 1] = '0';

		}
		else if (word[i] == '^' && word[i + 1] != '_' && word[i + 1] != ',' && word[i + 2] == '^')
		{
			word[i + 1] = '_';
		}
	}

	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] != '0' && word[i] != '@')
		{
			cout << word[i];
		}
	}

}