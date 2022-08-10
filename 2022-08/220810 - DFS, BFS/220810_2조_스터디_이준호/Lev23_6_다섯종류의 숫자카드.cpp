#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	int sum = 0;
	cin >> str;

	int start = -1;

	for (int i = 0; i < str.length(); i++) {
		if (!(str[i] >= '0' && str[i] <= '9')) 
		{
			
			string temp = str.substr(start + 1, i - start - 1);
			start = i;
			
			if (str[i] == '+')
			{
				sum += stoi(temp);
			}

			else if (str[i] == '-')
			{
				sum -= stoi(temp);
			}

		}
	}

	cout << sum;

	return 0;
}