#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int cntry[100];
int arr[100];
int sum_cntry[100];
int group_cnt[100];

void init()
{
	for (int i = 0; i < 100; i++)
	{
		arr[i] = -1;
		group_cnt[i] = 1;
	}

}
char findBoss(char tar)
{

	if (arr[tar] == -1) return tar;
	return findBoss(arr[tar]);
}


void unionGroup(char a, char b)


{
	if (findBoss(a) == findBoss(b)) return;


	if (a < b)
	{	//a ==a b== c
		sum_cntry[findBoss(a)] = cntry[findBoss(a) - 65] + cntry[findBoss(b) - 65];
		//cntry[findBoss(b)-65] = 0;
		//cntry[findBoss(a) - 65] = 0;
		arr[findBoss(b)] = findBoss(a);
		if (sum_cntry[findBoss(a)] == 0) return;
		group_cnt[findBoss(a)] += 1;
		//group_cnt[findBoss(b)] = 0;
	}
	else if (a > b)
	{  // a == D b ==B
		sum_cntry[findBoss(b)] = cntry[findBoss(b) - 65] + cntry[findBoss(a) - 65];
		//cntry[findBoss(a)-65] = 0;
		//cntry[findBoss(b) - 65] = 0;
		arr[findBoss(a)] = findBoss(b);
		if (sum_cntry[findBoss(b)] == 0) return;
		group_cnt[findBoss(b)] += 1;
		//group_cnt[findBoss(a)] = 0;
	}
}



int main()
{
	init();
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> cntry[i];
	}

	int sang;
	cin >> sang;
	for (int i = 0; i < sang; i++)
	{
		string option;
		char a_cntry, b_cntry;
		cin >> option >> a_cntry >> b_cntry;
		if (option == "alliance")
		{
			unionGroup(a_cntry, b_cntry);
		}
		else if (option == "war")
		{
			if (arr[a_cntry] == -1)
			{
				sum_cntry[findBoss(a_cntry)] = cntry[findBoss(a_cntry) - 65];

			}
			if (arr[b_cntry] == -1)
			{
				sum_cntry[findBoss(b_cntry)] = cntry[findBoss(b_cntry) - 65];
			}
			if (sum_cntry[findBoss(a_cntry)] > sum_cntry[findBoss(b_cntry)])
			{
				N -= group_cnt[findBoss(b_cntry)];
				group_cnt[findBoss(b_cntry)] = 0;
				cntry[findBoss(b_cntry) - 65] = 0;
				sum_cntry[findBoss(b_cntry)] = 0;
			}
			else if (sum_cntry[findBoss(a_cntry)] < sum_cntry[findBoss(b_cntry)])
			{
				N -= group_cnt[findBoss(a_cntry)];
				group_cnt[findBoss(a_cntry)] = 0;
				cntry[findBoss(a_cntry) - 65] = 0;
				sum_cntry[findBoss(a_cntry)] = 0;
			}
			else if (sum_cntry[findBoss(a_cntry)] == sum_cntry[findBoss(b_cntry)])
			{
				N -= (group_cnt[findBoss(a_cntry)] + group_cnt[findBoss(b_cntry)]);
				group_cnt[findBoss(a_cntry)] = 0;
				group_cnt[findBoss(b_cntry)] = 0;
				cntry[findBoss(a_cntry) - 65] = 0;
				cntry[findBoss(b_cntry) - 65] = 0;
				sum_cntry[findBoss(a_cntry)] = 0;
				sum_cntry[findBoss(b_cntry)] = 0;
			}
		}
	}
	cout << N;
}