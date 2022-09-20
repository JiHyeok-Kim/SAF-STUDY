#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
int used[1001]={0};
bool compare(int a, int b)
{
	if (a > b) return true;
	if (a < b) return false;
	return a > b;
}
int main()
{
	for (int i = 0; i < 10; i++)
	{
		int num;
		cin >> num;
		used[num]++;
	}
	sort(used.begin(), used.end(), compare);
	for (int i= 0; i<10; i++)
	{
		cout << used[i]<<' ';
	}
}