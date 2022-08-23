#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool survive[200];
char vect[200];
int population[200];

int n;
int result;

char Find(char now) {
	if (vect[now] == now) return now;

	return vect[now] = Find(vect[now]);
}

void UNION(char A, char B) {
	char pA = Find(A);
	char pB = Find(B);

	if (pA == pB) return;

	vect[pB] = pA;
}

void war(char A, char B) {
	int a = 0, b = 0;
	vector<char> war1;
	vector<char> war2;
	for (char ch = 'A'; ch < 'A' + n; ch++) {
		if (vect[ch] == Find(A)) {
			war1.push_back(ch);
			a += population[ch];
		}
		if (vect[ch] == Find(B)) {
			war2.push_back(ch);
			b += population[ch];
		}
	}

	if (a > b) {
		for (char loop : war2) survive[loop] = true;
	}
	else if (a == b) {
		for (char loop : war1) survive[loop] = true;
		for (char loop : war2) survive[loop] = true;
	}
	else {
		for (char loop : war1) survive[loop] = true;
	}
}

int main() {
	cin >> n;
	for (char ch = 'A'; ch < 'A' + n; ch++) {
		cin >> population[ch];
		vect[ch] = ch;
	}

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string str;
		cin >> str;
		if (str == "alliance") {
			char A, B;
			cin >> A >> B;
			if (survive[A] == true || survive[B] == true) continue;
			UNION(A, B);
		}
		else {
			char A, B;
			cin >> A >> B;
			if (survive[A] == true || survive[B] == true) continue;
			war(A, B);
		}
	}

	for (char ch = 'A'; ch < 'A' + n; ch++) {
		if (survive[ch] == false) result++;
	}

	cout << result;
	return 0;
}