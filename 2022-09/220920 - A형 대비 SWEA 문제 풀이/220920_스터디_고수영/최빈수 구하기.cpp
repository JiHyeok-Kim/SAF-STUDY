#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;



int main()
{
	int N,T;
	cin >> N;
	for (int t = 0; t < N; t++)
	{
		int dat[101] = { 0, };
		int max_num = -1;
		int max_cnt = -1;

		cin >> T;
		for (int i = 0; i < 1000; i++)
		{
			int num;
			cin >> num;
			dat[num]++;
		}

		for (int i = 1; i <= 100; i++)
		{
			if (dat[i] >= max_cnt)
			{
				max_cnt = dat[i];
				max_num = i;

				if (dat[i] == max_cnt)
				{
					if (i > max_num)
						max_num = i;
				}
			}
		}

		cout << "#" << T << " " << max_num << '\n';
	}


	return 0;

}