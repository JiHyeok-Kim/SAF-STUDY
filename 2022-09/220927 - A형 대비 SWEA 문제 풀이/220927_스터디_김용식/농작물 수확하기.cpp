#include <iostream>
#include <queue>
#include <string>
using namespace std;
int N;
int sum = 0;

int Arr[50][50] = { 0 };

void input() {
	sum = 0;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			Arr[i][j] = str[j] - '0';
		}
	}
	return;
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int Tc = 1; Tc <= tc; Tc++) {
		cin >> N;
		input();
		int n = (N - 1) / 2;
		int consume = -1;
		for (int i = 0; i < N; i++) {
			if (i > N / 2)consume--;
			else consume++;
			for (int j = n-consume; j <= n+consume; j++) {
				sum += Arr[i][j];
			}
		}

		cout <<"#"<<Tc<<" "<<sum<<'\n';
	}



	return 0;
}