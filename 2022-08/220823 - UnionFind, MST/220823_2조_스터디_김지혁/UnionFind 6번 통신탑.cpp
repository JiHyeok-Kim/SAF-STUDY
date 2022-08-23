#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int y;
	int x;
	int R;
};

int N;
int line[3001];
vector<Node> vect;
int cnt;

int findBoss(int tar)
{
	if (line[tar] == tar) return tar;

	int ret = findBoss(line[tar]);
	line[tar] = ret;
	return ret;
}

void unionGroup(int a, int b)
{
	int t1 = findBoss(a);
	int t2 = findBoss(b);
	if (t1 == t2) return;

	line[t2] = t1;
	cnt++;
	return;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	//freopen_s(new FILE*, "test.txt", "r", stdin);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		vect.clear();
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			line[i] = i;
		}

		for (int i = 0; i < N; i++)
		{
			int y, x;
			int R;
			cin >> y >> x >> R;
			vect.push_back({ y, x, R });
		}

		cnt = 0;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (y == x) continue;
				if (findBoss(y) == findBoss(x)) continue;
				int ret = (vect[y].y - vect[x].y) * (vect[y].y - vect[x].y) + (vect[y].x - vect[x].x) * (vect[y].x - vect[x].x);
				if ((vect[y].R + vect[x].R) * (vect[y].R + vect[x].R) >= ret)
				{
					unionGroup(y, x);
				}
			}
		}
		int ans = N - cnt;
		cout << ans << "\n";

	}

	return 0;
}