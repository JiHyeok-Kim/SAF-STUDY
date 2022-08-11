#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;
struct Node {
	int left;
	int right;
};

int N;
vector<vector<Node>>arr(1001);


void dfs1(int x)
{
	if (arr[x][0].left != -1) dfs1(arr[x][0].left);
	cout << x << " ";
	if (arr[x][0].right != -1) dfs1(arr[x][0].right);

}

void dfs2(int x)
{
	cout << x << " ";
	if (arr[x][0].left != -1) dfs2(arr[x][0].left);
	if (arr[x][0].right != -1) dfs2(arr[x][0].right);

}


void dfs3(int x)
{
	if (arr[x][0].left != -1) dfs3(arr[x][0].left);
	if (arr[x][0].right != -1) dfs3(arr[x][0].right);
	cout << x << " ";
	
}



int main()
{
	cin >> N;
	for (int i = 1; i <= 11; i++)
	{
		int from;
		int left, right;
		cin >> from >> left >> right;
		arr[from].push_back({ left,right });
	}
	int start = 1;

	dfs1(start);
	cout << '\n';

	dfs2(start);
	cout << '\n';

	dfs3(start);
	
}