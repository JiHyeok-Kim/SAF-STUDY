#include <iostream>
#include <algorithm>
using namespace std;

int N, L;
int list[1100];

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) cin >> list[i];
	sort(list, list + N);
	int s = 0, e = 1, cnt = 1;
	while (e < N) {
		int term = list[e] - list[s];
		if (term >= L) {
			s = e;
			e++;
			cnt++;
		}
		else e++;
	}
	cout << cnt;
	return 0;
}