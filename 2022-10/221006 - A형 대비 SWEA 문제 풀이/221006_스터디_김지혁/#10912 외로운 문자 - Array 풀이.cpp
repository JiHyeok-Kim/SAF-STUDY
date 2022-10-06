#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) 
	{
		int bucket[123] = { 0 };
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			bucket[str[i]]++;
		}
		
		int flag = 0;
		cout << "#" << tc << " ";
		for (int i = 97; i <= 122; i++) {
			char ch = i;
			if (bucket[i] % 2 == 1) { 
				flag = 1;
				cout << ch;
			}
		}
		if (flag == 0) cout << "Good";
		cout << "\n";
	}

	return 0;
}