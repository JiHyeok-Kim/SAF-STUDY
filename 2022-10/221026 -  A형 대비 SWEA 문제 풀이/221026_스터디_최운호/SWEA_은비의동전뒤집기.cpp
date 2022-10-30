#include <iostream>
#include <math.h>
using namespace std;

long long memo[1001];

long long fac(int num) {
	long long result = 1;
	for (int i = 1; i <= num; i++) {
		result *= i;
		result %= 1000000007;
	}
	return result;
}

long long getDP(int now) {
	if (now == 1) return 0;
	if (memo[now] != 0) return memo[now];

	long long tmp = fac(now - 1);
	memo[now] = (now * getDP(now - 1) + (now / 2) * tmp) % 1000000007;

	return memo[now];
}

int main()
{
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;
		cout << "#" << t << " " << getDP(n) << '\n';
	}
	return 0;
}