#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string str = "MINCODING";
char arr[100];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		int it = 0;
		for (int j = 0; j < str.size(); j++)
		{
			if (arr[i] == str[j])
			{
				cout << "O";
				it++;
				break;
			}
		}

		if (it == 0)
		{
			cout << "X";
		}


	}
}