#include <iostream>
using namespace std;

int N, M;
int land[10001];

void init()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> land[i];
	}

	return;
}

int solve()
{
	int cnt, idx, sum;
	cnt = idx = sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = idx; j < N; j++) {
			if (sum + land[j] > M) break;
			sum += land[j];
			if (sum == M) cnt++;
			idx++;
		}
		sum -= land[i];
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
		cout << "#" << tc << " " << solve() << "\n";
	}

	return 0;
}