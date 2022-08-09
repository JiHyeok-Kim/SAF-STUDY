#include<iostream>
using namespace std;

char name[5][4] = {
	"ABC",
	"AGH",
	"HIJ",
	"KAB",
	"ABC",
};

int main()
{
	int bucket[200] = { 0 };
	int x, y;

	for (y = 0; y < 5; y++)
	{
		for (x = 0; x < 3; x++)
		{
			bucket[name[y][x]]++;
		}
	}

	for (y = 0; y < 200; y++)
	{
		if (bucket[y] > 0)
		{
			for (x = 0; x < bucket[y]; x++)
			{
				cout << (char)(y);
			}
		}
	}

	return 0;
}