#include<iostream>

using namespace std;



int arr[1001][1001];
int used[10000001];
int main()
{
	int h, w;
	cin >> h >> w;


	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> arr[i][j];
			used[arr[i][j]]++;
		}
	}
	int max = -1;
	int max_idx = 0;
	for (int i = 0; i < 10000001; i++)
	{
		if (used[i] > max)
		{
			max = used[i];
			max_idx = i;
		}

	}
	cout << max_idx;

}