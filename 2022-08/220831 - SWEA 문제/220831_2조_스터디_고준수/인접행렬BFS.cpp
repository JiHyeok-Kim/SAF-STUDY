#include <iostream>
#include <queue>
#include <vector>
using namespace std;


queue<int> q;



int main() {
	int num;
	cin >> num;
	vector<vector<int>> alist(num, vector<int>(num, 0));
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			cin >> alist[i][j];
			//cout << alist[i][j]<< " ";

		}
	}
	int used[10] = { 0 };
	q.push(0);
	while (!q.empty())
	{
		int now = q.front();
		used[now] = 1;
		q.pop();

		cout << now << " ";


		for (int next = 0; next < num; next++)
		{
			if (alist[now][next] == 0)
			{
				continue;
			}
			if (used[next] == 1)
			{
				continue;
			}
			q.push(next);
			used[next] = 1;



		}
	}



	return 0;

}