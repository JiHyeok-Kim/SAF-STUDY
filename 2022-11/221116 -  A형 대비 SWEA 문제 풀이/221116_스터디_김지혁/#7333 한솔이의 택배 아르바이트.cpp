#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int hv[100];
int lt[100];

void init()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> hv[i];
		lt[i] = hv[i];
	}

	sort(hv, hv + N, greater<int>());
	sort(lt, lt + N);
	return;
}

int solve()
{
	int flag = 0;
	int idxh, idxl, cnt;
	cnt = 0;
	idxh = idxl = -1;
	while (1)
	{
		if (idxh + 1 + idxl + 1 == N) break;
		else if (idxh + 1 + idxl + 1 > N) {
			flag = 1;
			break;
		}
		idxh++;
		if (hv[idxh] >= 50) {
			cnt++;
			continue;
		}
		else {
			float n = hv[idxh];
			int num = ceil(50 / n);
			num--;
			idxl += num;
			cnt++;
		}
	}
	if (flag == 1) {
		cnt--;
	}

	return cnt;
}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(NULL);
	cout.tie(NULL);
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