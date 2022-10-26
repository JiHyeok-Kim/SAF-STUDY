#include <iostream>
using namespace std;

int N;
long long num[1001];

long long dfs(int lev)
{
	if (num[lev] > 0) {
		return num[lev];
	}

	if (lev == 1){
		return 0;
	}
	
	long long n = 1;
	for (int i = 1; i < lev; i++){
		n *= i;
		n %= 1000000007;
	}

	return num[lev] = (lev* dfs(lev - 1) + (lev / 2) * n) % 1000000007;
}


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
		cin >> N;
		cout << "#" << tc << " " << dfs(N) << "\n";
	}

	return 0;
}