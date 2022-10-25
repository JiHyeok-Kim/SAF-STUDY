#include <iostream>
#include <cstring>
using namespace std;

int N, M;

int parents[101];
int num[101];

int Find(int now)
{
	if (parents[now] == now) return now;

	int ret = Find(parents[now]);
	parents[now] = ret;

	return ret;
}

void Union(int a, int b)
{
	int t1 = Find(a);
	int t2 = Find(b);
	if (t1 == t2) return;
	parents[t2] = t1;
}

void init()
{
	memset(parents, 0, sizeof(parents));
	memset(num, 0, sizeof(num));
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		parents[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		int maxi, mini;
		maxi = max(a, b);
		mini = min(a, b);
		Union(maxi, mini);
	}

	return;
}

int ans()
{
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (num[Find(i)] == 1) continue;
		num[Find(i)] = 1;
		cnt++;
	}

	return cnt;
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
		cout << "#" << tc << " " << ans() << "\n";
	}

	return 0;
}