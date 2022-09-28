#include <iostream>
#include <string>

using namespace std;
string Str;
int N;
int real;

int Find(int N) {
	for (int i = 0; i < N; i++) {
		if (Str[i] != Str[N + i]) return 1;
	}
	return 0;
}



int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int tc;
	cin >> tc;
	for (int k = 1; k <= tc; k++) {
		cin >> Str;
		char A = Str[0];
		int B = 1;
		while (1) {
			N = Str.find(A, B);
			real = Find(N);
			if (real == 0)break;
			B = N+1;
		}
		cout << "#" << k << " " << N << '\n';
	}

	return 0;
}