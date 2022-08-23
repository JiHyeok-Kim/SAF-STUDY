#include <iostream>
#include <string>
using namespace std;
string input;
string result[100];
string str = "";
int cnt = 0;
int main()
{
	cin >> input;
	for (int i = 0; i <= input.size(); i++)
	{
		if (int(input[i]) >= 65 && int(input[i]) <= 90)
		{
			str += input[i];

		}
		else if (input[i] == '_' && str.size() > 0)
		{
			result[cnt] = str;
			str = "";
			cnt++;
		}
		else if (i == input.size())
		{
			result[cnt] = str;
		}
	}
	for (int i = 0; i <= cnt; i++)
	{
		if (result[i] != " ")
		{
			cout << i + 1 << '#' << result[i] << "\n";
		}
	}

}