#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


string str;
int used[30] = { 0 };
int max1 = -1;
int max_idx = 0;
int main() {
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		used[int(str[i]) - 65] += 1;
	}
	for (int i = 0; i < 30; i++)
	{
		if (used[i] > max1)
		{
			max1 = used[i];
			max_idx = i;
		}
	}
	cout << char(max_idx + 65) << '\n';

	for (int i = 0; i < 30; i++)
	{
		if (used[i] == 0)
		{
			cout << char(i + 65) << '\n';
			break;
		}
	}




}