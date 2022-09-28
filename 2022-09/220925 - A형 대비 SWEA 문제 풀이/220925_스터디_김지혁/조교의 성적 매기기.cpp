#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
	int idx;
	int score;
};

bool cmp(Node t, Node v)
{
	return t.score > v.score;
}

int N, K;
string score[10] = { "A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0" };

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		Node st[101] = { 0 , 0, 0 , 0, 0 };
		cin >> N >> K;
		for (int i = 0; i < N; i++)
		{
			st[i].idx = i + 1;
			int score35, score45, score20;
			cin >> score35 >> score45 >> score20;
			st[i].score = (score35 * 35 + score45 * 45 + score20 * 20);
		}

		sort(st, st + N, cmp);
		for (int i = 0; i < N; i++)
		{
			if (st[i].idx == K)
			{
				cout << "#" << tc << " " << score[i / (N / 10)] << "\n";
				break;
			}
		}
	}

	return 0;
}