#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s[4] = {};
	int max_len = -1, min_len = 10000;
	int max_index,min_index;
	for (int a = 0; a < 4; a++)
	{
		string x;
		cin >> x;
		s[a] = x;
		int len = x.length();

		if (len>max_len)
		{
			max_len = len;
			max_index = a;
		}
		if (len < min_len)
		{
			min_len = len;
			min_index = a;
		}

	}
	cout << "긴문장:" << max_index << "\n";
	cout << "짧은문장:" << min_index << "\n";

	return 0;
}