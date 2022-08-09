#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int arr[100] = { 0 };

	for (int i = 0; i < s.size(); i++)
	{
		if (arr[s[i]] != 0)continue;
		arr[s[i]] = 1;
	}
	for (int i = 65; i < 95; i++)
	{
		if (arr[i] ==1)cout << char(i);
	}
}