#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node {
	int score;
	int solve;
	int order;
	string record;
};

bool cmp(Node t, Node v) {
	if (t.score > v.score) return 1;
	else if (t.score < v.score) return 0;
	if (t.solve > v.solve) return 1;
	else if (t.solve < v.solve) return 0;
	return t.order < v.order;
}

int N, T, P;
Node sassung[2000];
int cnt[2000];

void init()
{
	memset(cnt, 0, sizeof(cnt));

	cin >> N >> T >> P;
	for (int i = 0; i < N; i++) {
		int solve = 0;
		string str;
		for (int j = 0; j < T; j++) {
			int n;
			cin >> n;
			str += '0' + n;
			if (n == 1) solve++;
			else if (n == 0) cnt[j]++;
		}
		sassung[i].solve = solve;
		sassung[i].order = i + 1;
		sassung[i].record = str;
	}

	return;
}

void ans()
{
	for (int i = 0; i < N; i++) {
		int score = 0;
		for (int j = 0; j < T; j++) {
			if (sassung[i].record[j] == '1') score += cnt[j];
		}
		sassung[i].score = score;
	}

	sort(sassung, sassung + N, cmp);

	for (int i = 0; i < N; i++) {
		if (sassung[i].order == P) {
			cout << sassung[i].score << " ";
			cout << i + 1 << "\n";
		}
	}
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		cout << "#" << tc << " ";
		ans();
	}


	return 0;
}