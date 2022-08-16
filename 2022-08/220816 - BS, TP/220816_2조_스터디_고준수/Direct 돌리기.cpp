#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

string input[3][3] = { "BHC","BBQ","KFC","MC","7AVE","PAPA","DHC","OBS","MOMS" };
string answer;
int main()
{
	int y, x;
	cin >> y >> x;

	int direct_y[4] = { -1, 0, 1, 0 };
	int direct_x[4] = { 0, -1, 0, 1 };
	for (int i = 0; i < 4; i++)
	{
		int dy = y + direct_y[i];
		int dx = x + direct_x[i];
		if (dx < 0 || dy < 0 || dx >= 3 || dy >= 3) continue;
		answer += input[dy][dx];
	}
	cout << answer;
}