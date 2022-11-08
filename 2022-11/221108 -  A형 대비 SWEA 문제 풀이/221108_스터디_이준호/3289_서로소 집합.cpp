#include <iostream>
using namespace std;

int N, M;
int flag, a, b;
int arr[1000010];

int Find(int now) {
	if (arr[now] == now) return now;

	int ret = Find(arr[now]);
	arr[now] = ret;

	return ret;
}

void Union(int aa, int bb) {
	int t1 = Find(aa);
	int t2 = Find(bb);
	if (t1 == t2) return;
	arr[t2] = t1;
}

int main()
{	
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		for (int i = 0; i < 1000010; i++) {
			arr[i] = i;
		}

		cin >> N >> M;
		cout << "#" << tc << " ";
		for (int i = 0; i < M; i++) {
			cin >> flag >> a >> b;

			if (flag == 1) {
				int ans1 = Find(a);
				int ans2 = Find(b);
				if (ans1 == ans2) cout << 1;
				else cout << 0;
			}
			else {
				Union(a, b);
			}
		}
		cout << "\n";

	}
	

	return 0;
}