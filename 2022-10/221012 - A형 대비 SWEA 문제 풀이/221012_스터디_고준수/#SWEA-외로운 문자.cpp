#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
string word;

typedef struct
{
	int i;
	int j;
}Node;
Node now;
int find_idx()
{
	if (word.size() == 0) return -1;
	for (int i = 0; i < word.size(); i++)
	{
		for (int j = i + 1; j < word.size(); j++)
		{
			if (word[i] == word[j])
			{
				now.i = i;
				now.j = j;
				return 1;
			}
		}
	}
	return -1;
}

int main()
{
	int testcase;
	cin >> testcase;

	for (int tc = 0; tc < testcase; tc++)
	{

		cin >> word;

		while (find_idx() != -1)
		{
			int idx = find_idx();

			word.erase(now.j, 1);
			word.erase(now.i, 1);
		}
		if (word.size() == 0)
		{
			cout << '#' << tc + 1 << ' ' << "Good" << '\n';
		}
		else if (word.size() != 0)
		{
			sort(word.begin(), word.end());
			cout << '#' << tc + 1 << ' ' << word << '\n';
		}

	}




	return 0;
}