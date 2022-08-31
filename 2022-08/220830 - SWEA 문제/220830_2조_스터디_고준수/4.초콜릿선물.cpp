#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <valarray>
#include <string>
using namespace std;



string input;
int used[30] = { 0 };
int main()
{
	cin >> input;
	for (int i = 0; i < input.size(); i++)
	{
		used[int(input[i]) - 65] += 1;
	}

	for (int i = 0; i < 30; i++)
	{
		if (used[i] >= 1)
		{
			cout << char(i + 65);
		}
	}
}