#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

vector<int> v;
int result = 0;
int tc_cnt = 1;
int main()
{

	int tc;
	cin >> tc;
	for (int testcase=0; testcase < tc; testcase++)
	{


		int N;
		cin >> N;

		int K;
		cin >> K;


		int map[15][15];
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
			}
		}

		int width_cnt = 0;
		//가로
		for (int i = 0; i < N; i++)
		{
			v.clear();
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] == 0 && width_cnt==0) continue;
				if (map[i][j] == 0 && width_cnt != 0)
				{
					v.push_back(width_cnt);
					width_cnt = 0;
				}
				else if (map[i][j] == 1)
				{
					width_cnt++;
				}
			}
			v.push_back(width_cnt);
			width_cnt = 0;
			for (int j = 0; j < v.size(); j++)
			{
				if (v[j] == K)
				{
					result++;
				}
			}

		}


		//세로
		int height_cnt = 0;
		for (int i = 0; i < N; i++)
		{
			v.clear();
			for (int j = 0; j < N; j++)
			{
				if (map[j][i] == 0 && height_cnt == 0) continue;
				if (map[j][i] == 0 && height_cnt != 0)
				{
					v.push_back(height_cnt);
					height_cnt = 0;
					//height_cnt = 0;
				}
				else if (map[j][i] == 1)
				{
					height_cnt++;
				}
			}
			v.push_back(height_cnt);
			height_cnt = 0;
			for (int j = 0; j < v.size(); j++)
			{
				if (v[j] == K)
				{
					result++;
				}
			}

		}


		cout << "#" << tc_cnt << ' ' << result << '\n';
		result = 0;
		tc_cnt++;


	};
	return 0;
}
