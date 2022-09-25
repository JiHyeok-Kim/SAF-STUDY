#include <iostream>
using namespace std;

int A, B;
int prime[] = { 2,3,5,7,11,13,17 };
double result;

int comb(int tar) {
	double up = 1, down = 1;
	for (int i = 0; i < tar; i++) up *= 18 - i;
	for (int i = 0; i < tar; i++) down *= tar - i;
	return up / down;
}

double percent(int skill,int tar) {
	double perc = 1.0;
	double ski1 = skill / 100.0;
	double ski2 = (100 - skill) / 100.0;
	for (int i = 0; i < tar; i++) perc *= ski1;
	for (int i = 0; i < 18 - tar; i++) perc *= ski2;
	return perc;
}

void solution() {
	double percA = 0, percB = 0;
	for (int i = 0; i < 7; i++) {
		int comb1 = comb(prime[i]);
		percA += comb1 * percent(A, prime[i]);
		percB += comb1 * percent(B, prime[i]);
	}
	result = 1 - ((1 - percA) * (1 - percB));
}

void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> A >> B;
		solution();
		cout << "#" << t << " " << result << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(6);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}