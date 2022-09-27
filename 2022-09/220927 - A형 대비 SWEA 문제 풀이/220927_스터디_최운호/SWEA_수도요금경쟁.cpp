#include <iostream>
using namespace std;

int get(int r, int w, int q, int s) {
	if (r >= w) return q;
	else return q + ((w - r) * s);
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int p, q, r, s, w;
		cin >> p >> q >> r >> s >> w;

		int a = 0;
		int b = 0;
		int answer = 0;
		a = p * w;
		b = get(r, w, q, s);
		if (a > b) answer = b;
		else answer = a;

		cout << "#" << t << " " << answer << '\n';
	}
	return 0;
}