#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
	int idx;
	int score35;
	int score45;
	int score20;
	int score;
};

bool cmp(Node t, Node v)
{
	if (t.score > v.score) return 1;
	if (t.score < v.score) return 0;

	return t.idx < v.idx;
}

int N, K;
string score[10] = { "A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0" };

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);

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
			cin >> st[i].score35 >> st[i].score45 >> st[i].score20;
			st[i].score = (st[i].score35 * 35 + st[i].score45 * 45 + st[i].score20 * 20);
		}

		sort(st, st + N, cmp);
		for (int i = 0; i < N; i++)
		{
			if (st[i].idx == K)
			{
				cout << "#" << tc << " " << score[i / (N/10)] << "\n";
				break;
			}
		}
	}

	return 0;
}