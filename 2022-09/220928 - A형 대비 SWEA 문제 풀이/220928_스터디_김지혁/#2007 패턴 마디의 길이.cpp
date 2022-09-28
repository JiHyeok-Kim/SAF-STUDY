#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		string str;
		char ch[10] = { 0 };
		cin >> str;

		for (int i = 0; i < 10; i++)
		{
			int flag = 0;
			ch[i] = str[i];
			int s = 1;
			while (1)
			{
				int ret = str.find(ch, s);
				if (ret == -1) break;
				if (ret - s + 1 == strlen(ch)) {
					s = ret + 1;
				}
				else { flag = 1; break; }
			}
			if (flag == 0) { cout << "#" << tc << " " << i + 1 << "\n"; break; }
		}
	}

	return 0;
}