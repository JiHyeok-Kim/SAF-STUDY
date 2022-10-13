#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct point {
	int x;
	int y;
};

int T;
int N, M, C;
int start_x,start_y;
int map[11][11] = { 0, };
int used[11]= { 0, };

int A_ret;
int B_ret;

int st = 0;
int A_maxi = -21e6;
int B_maxi = -21e6;
int TMP = -21e6;
int maxi = -21e6;

vector<int>path;
vector<int>A;
vector<int>B;

void input()
{
	cin >> N >> M >> C;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
}


void hunny(vector<int> now,int sum_val, vector<int>path)
{
	if (sum_val > C)return;

	if (sum_val!=0 && sum_val <= C)
	{
		int now_now = 0;
		for (int a = 0; a < path.size(); a++)
		{
			now_now += pow(path[a], 2);
		}
		//maxi비교
		TMP = max(TMP, now_now);

	}

	if (st >= now.size())return;
	for (int i = st; i < now.size(); i++)
	{
		if (used[i] == 1)continue;
		used[i] = 1;
		path.push_back(now[i]);
		st++;
		hunny(now, sum_val + now[i], path);
		st--;
		path.pop_back();
		used[i] = 0;

	}


}


int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		input();
		maxi = -21e6;
		//첫째
		for (int i = 0; i <= N; i++)
		{
			
			for (int j = 0; j <= N - M; j++)
			{
				//A벌꿀 채춰
				for (int v=0; v < M; v++)
				{
					point A_debug = { i,j+v };
					A.push_back(map[i][j + v]);
					int debug1 = 10;
					
					start_x = i;
					start_y = j + v + 1;
				}

				//A벌꿀 계산
				TMP = 0;
				st = 0;
				hunny(A,0,path);
				A_maxi = TMP;

				//B벌꿀 채취
				while (1)
				{
					if (start_y + M - 1 > N - 1)
					{
						start_x++;
						start_y = 0;
					}
					if (start_x >= N)break;

					//B벌꿀 채취
					for (int a = 0; a < M; a++)
					{
						point B_debug = { start_x,start_y + a };
						B.push_back(map[start_x][start_y + a]);
					}
					//B벌꿀 계산
					TMP = 0;
					st = 0;
					hunny(B, 0, path);
					B_maxi = TMP;

					B.clear();
					//max 비교
					maxi = max(maxi, A_maxi + B_maxi);

					//한칸 이동
					start_y++;
				}
				A.clear();
			}
		}

		cout << "#" << tc << " " << maxi << '\n';
	}

	return 0;
}