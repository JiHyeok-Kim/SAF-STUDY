#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
	int num;
	char c;
};

bool compare(Node t, Node v)
{
	if (t.num < v.num)return 1;
	if (t.num > v.num)return 0;

	if (t.c < v.c)return 1;
	else return 0;
}

int main() 
{
	int n;
	cin >> n;
	vector<Node>arr;
	for (int i = 0; i < n; i++)
	{
		int a;
		char b;
		cin >> a >> b;
		arr.push_back({ a,b });
	}

	sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i].num << " " << arr[i].c << '\n';
	}

}