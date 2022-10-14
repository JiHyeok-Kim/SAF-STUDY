#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

vector<string> v;

int main()
{
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		v.clear();

		int num;
		cin >> num;
		string word;
		cin >> word;
		string sep_w = word;
		v.push_back(sep_w);
		for (int i = 0; i < word.size() - 1; i++)
		{

			sep_w.erase(0, 1);
			v.push_back(sep_w);
		}
		sort(v.begin(), v.end());
		cout << '#' << tc + 1 << ' ' << v[num - 1] << '\n';
	}
}