#include <iostream>
using namespace std;

struct Node {
	int a, b;
};

int N, maxi;
Node num[20];
bool used[20];
int ans[40];

void init()
{
	maxi = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i].a >> num[i].b;
	}

	return;
}

void DFS(int lev, int b, int arr[40])
{
	if (lev > maxi) {
		for (int i = 0; i < lev * 2; i++) {
			ans[i] = arr[i];
		}
		maxi = lev;
	}

	for (int i = 0; i < N; i++) {
		if (used[i] == true) continue;
		if (b != num[i].a) continue;
		used[i] = true;

		arr[lev * 2] = num[i].a;
		arr[lev * 2 + 1] = num[i].b;

		DFS(lev + 1, num[i].b, arr);

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
		for (int i = 0; i < N; i++) {
			used[i] = true;

			int arr[40] = { 0 };
			arr[0] = num[i].a;
			arr[1] = num[i].b;

			DFS(1, num[i].b, arr);

			used[i] = false;
		}

		cout << "#" << tc;
		for (int i = 0; i < maxi * 2; i++) {
			cout << " " << ans[i];
		}
		cout << "\n";
	}

	return 0;
}