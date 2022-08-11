#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int path[30] = { 0 };
int arr[3] = { 1,2,3 };
int sum = 0;
int cnt = 0;

void dfs(int lev,int sum)
{
	if (sum == N)
	{
		cnt++;
		return;
	}
	if (sum > N)return;

	for (int i = 0; i < 3; i++)
	{
		path[lev] = arr[i];
		dfs(lev + 1, sum + arr[i]);
		path[lev] = 0;
	}


}



int main()
{
	cin >> N;
	
	sum = 0;
	dfs(0, sum);
	cout << cnt;
	
}