#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct sketchbook {
	char image[3][3];
};
int main()
{
	struct sketchbook a;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> a.image[i][j];
		}
	}

	int used[30] = { 0 };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			used[int(a.image[i][j]) - 65]++;
		}
	}

	for (int i = 0; i < 30; i++)
	{
		if (used[i] >= 1)
		{
			cout << char(i + 65);
		}

	}



	return 0;
}