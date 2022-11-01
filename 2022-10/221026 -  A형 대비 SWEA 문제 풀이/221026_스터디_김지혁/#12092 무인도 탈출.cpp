#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int side[3], maxi, mini;
};

bool cmp(Node t, Node v) {
	return t.mini < v.mini;
}

int N, ans;
Node box[20];
bool used[20];

void init()
{
	ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		box[i].side[0] = a;
		box[i].side[1] = b;
		box[i].side[2] = c;
		int maxi;
		maxi = max(max(a, b), c);
		int d = a * b;
		int e = a * c;
		int f = b * c;
		int mini;
		mini = min(min(d, e), f);
		box[i].maxi = maxi;
		box[i].mini = mini;
	}

	sort(box, box + N, cmp);
	return;
}

void dfs(int lev, int high, int side1, int side2) 
{
	if (high > ans) ans = high;
	if (lev == N) {
		return;
	}

	if (lev == 0) {
		for (int i = 0; i < N; i++) {
			used[i] = true;
			dfs(lev + 1, high + box[i].side[0], box[i].side[1], box[i].side[2]);
			dfs(lev + 1, high + box[i].side[1], box[i].side[0], box[i].side[2]);
			dfs(lev + 1, high + box[i].side[2], box[i].side[0], box[i].side[1]);
			used[i] = false;
		}
	}

	for (int i = 0; i < N; i++) {
		if (used[i] == true) continue;
		// 가지치기 1 : 앞으로의 면적이 현재 면적보다 작으면 return한다.
		if (side1 * side2 < box[i].mini) return;
		// 가지치기 2 : 현재 면적보다 작은 면적의 max 길이의 합이 ans보다 작다면 return한다.
		int sum = 0;
		for (int j = 0; j < N; j++) {
			if (side1 * side2 < box[i].mini) continue;
			sum += box[j].maxi;
		}
		if (sum <= ans) return;
		used[i] = true;
		for (int j = 0; j < 3; j++) {
			for (int k = j + 1; k < 3; k++) {
				int J = box[i].side[j];
				int K = box[i].side[k];
				if ((J <= side1 && K <= side2) || (K <= side1 && J <= side2)) {
					int l = 3 - j - k;
					dfs(lev + 1, high + box[i].side[l], J, K);
				}
			}
		}
		used[i] = false;
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
		init();
		dfs(0, 0, 0, 0);
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}