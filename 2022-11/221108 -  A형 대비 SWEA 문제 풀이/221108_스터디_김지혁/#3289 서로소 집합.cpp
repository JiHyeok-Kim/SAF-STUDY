#include <iostream>
using namespace std;

int N, M;
int parents[1000001];

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
	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		parents[i] = i;
	}

	int cmd, a, b;
	for (int i = 0; i < M; i++) {
		cin >> cmd >> a >> b;
		if (cmd == 0) Union(a, b);
		else if (cmd == 1 && Find(a) == Find(b)) cout << 1;
		else if (cmd == 1 && Find(a) != Find(b)) cout << 0;
	}

	return;
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
		cout << "#" << tc << " ";
		init();
		cout << "\n";
	}

	return 0;
}