#include <iostream>
#include <math.h>
using namespace std;

int sucess[7] = { 2,3,5,7,11,13,17 };
int combi[19][19];

void makeCnt() {
	combi[1][0] = 1;
	combi[1][1] = 1;
	for (int i = 2; i <= 18; i++) {
		combi[i][0] = 1;
		for (int j = 1; j <= 18; j++) {
			combi[i][j] = combi[i - 1][j - 1] + combi[i - 1][j];
		}
	}
}
double calc(int percent, int s) {
	double R = 1.0;
	double P = (double)percent / 100.0;
	for (int i = 0; i < s; i++) R = R * P;

	return R;
}
int main() {
	int tc;
	cin >> tc;
	cout << fixed;
	cout.precision(6);
	for (int t = 1; t <= tc; t++) {
		int ska, skb;
		int Nska, Nskb;
		cin >> ska >> skb;
		Nska = 100 - ska;
		Nskb = 100 - skb;

		makeCnt();

		double aTotal = 0.0;
		double bTotal = 0.0;

		for (int i = 0; i < 7; i++) {
			double aSucess = calc(ska, sucess[i]);
			double aFail = calc(100 - ska, 18 - sucess[i]);
			double bSucess = calc(skb, sucess[i]);
			double bFail = calc(100 - skb, 18 - sucess[i]);

			aTotal = aTotal + combi[18][sucess[i]] * aSucess * aFail;
			bTotal = bTotal + combi[18][sucess[i]] * bSucess * bFail;
		}

		double answer = 1 - ((1 - aTotal) * (1- bTotal));

		cout << "#" << t << " " << answer << '\n';
	}
	return 0;
}