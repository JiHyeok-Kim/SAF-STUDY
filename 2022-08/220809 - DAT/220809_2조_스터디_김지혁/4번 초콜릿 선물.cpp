#include <iostream>
using namespace std;

string str;
int bucket[91];
int main()
{
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		bucket[str[i]]++;
	}
	for (int i = 65; i < 91; i++) {
		if (bucket[i] >= 1) { cout << char(i); }
	}

	return 0;
}