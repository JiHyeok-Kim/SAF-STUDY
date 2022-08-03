#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
	string name;
	int score;
	int index;

};

bool compare(Node t, Node v)
{
	if (t.score > v.score)return 1;
	if (t.score < v.score)return 0;

	if (t.index > v.index)return 1;
	if (t.index < v.index)return 0;
}

int main() 
{
	vector<Node>arr;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string a;
		int b;
		cin >> a >> b;
		arr.push_back({ a,b,i });
		sort(arr.begin(), arr.end(), compare);
		for (int t = 0; t < arr.size(); t ++ )
		{
			if (t > 2)continue;
			cout << arr[t].name << " ";
		}
		cout << '\n';
	}

}