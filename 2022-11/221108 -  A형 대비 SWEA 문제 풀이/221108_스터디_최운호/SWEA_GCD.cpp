#include <iostream>
using namespace std;
struct Node {
	long long A;
	long long B;
};
Node memo[91];

void dp()
{
	memo[0].A = 1;
	memo[0].B = 1;
	for (int i = 1; i <= 90; i++) {
		memo[i].A = memo[i - 1].A + memo[i - 1].B;
		memo[i].B = memo[i - 1].A;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	dp();

	for (int t = 1; t <= tc; t++) {
		int K;
		cin >> K;
		cout << "#" << t << " " << memo[K].A << " " << memo[K].B << '\n';
	}
	return 0;

}