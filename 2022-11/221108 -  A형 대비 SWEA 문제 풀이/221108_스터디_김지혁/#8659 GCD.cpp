#include <iostream>
using namespace std;

struct Node {
	bool exist;
	long long a, b;
};

int K;
Node num[91];

void DFS(int lev)
{
	if (num[lev].exist == false) {
		DFS(lev - 1);
		num[lev].exist = true;
	}
	if (lev < 90 && num[lev].exist == true) {
		num[lev + 1].b = num[lev].a;
		num[lev + 1].a = num[lev].a + num[lev].b;
	}

	return;
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	num[1].exist = 1;
	num[1].a = 2;
	num[1].b = 1;

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> K;
		if (num[K].exist == false) DFS(K);
		cout << "#" << tc << " " << num[K].a << " " << num[K].b << "\n";
	}

	return 0;
}