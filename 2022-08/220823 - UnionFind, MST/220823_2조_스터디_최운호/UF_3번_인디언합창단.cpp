#include <iostream>
using namespace std;

char vect[200];
int group[200];
int n;

char Find(char now) {
	if (vect[now] == now) return now;

	return vect[now] = Find(vect[now]);
}
void UNION(char A, char B) {
	char pA = Find(A);
	char pB = Find(B);

	vect[pB] = pA;
}

int main() {
	cin >> n;

	for (char ch = 'A'; ch <= 'Z'; ch++) {
		vect[ch] = ch;
	}

	for (int i = 0; i < n; i++) {
		char ch1, ch2;
		cin >> ch1 >> ch2;
		if (Find(ch1) == Find(ch2)) continue;
		UNION(ch1, ch2);
	}

	for (char ch = 'A'; ch <= 'Z'; ch++) {
		group[Find(ch)]++;
	}

	int result = 0;
	int alone = 0;
	for (char ch = 'A'; ch <= 'Z'; ch++) {
		if (group[ch] > 1) result++;
		else if (group[ch] == 1) alone++;
	}

	cout << result << '\n' << alone;

	return 0;
}
