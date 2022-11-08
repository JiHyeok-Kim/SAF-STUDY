#include <iostream>
#include <string>
using namespace std;

int vect[1000001];
string answer = "";
int N, M;

int Find(int now) {
	if (vect[now] == now) {
		return now;
	}
	else return vect[now] = Find(vect[now]);
}

void UNION(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	vect[b] = a;
}

void init() {
	cin >> N >> M;

	answer = "";

	for (int i = 1; i <= N; i++) {
		vect[i] = i;
	}
}

int main()
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		init();

		for (int i = 0; i < M; i++) {
			int opp, a, b;
			cin >> opp >> a >> b;

			if (opp == 0) {
				UNION(a, b);
			}
			else {
				if (Find(a) == Find(b)) answer += '1';
				else answer += '0';
			}
		}

		cout << "#" << t << " " << answer << '\n';
	}
	return 0;
}