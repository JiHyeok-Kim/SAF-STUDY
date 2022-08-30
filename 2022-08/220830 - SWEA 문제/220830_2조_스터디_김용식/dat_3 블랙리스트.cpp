#include <iostream>
using namespace std;
int Apart[1001][1001] = { 0 };
int Black[1001][1001] = { 0 };
int dat_Apart[100001] = { 0 };
int dat_Black[100001] = { 0 };
int main() { 
	
	int HH, HW;
	cin >> HH >> HW;
	int cntA = 0;
	for (int i = 0; i < HH; i++) {
		for (int j= 0; j < HW; j++) {
			cin >> Apart[i][j];
			dat_Apart[Apart[i][j]]++;
			cntA++;
		}
	}
	int BH, BW;
	cin >> BH >> BW;
	for (int i = 0; i < BH; i++) {
		for (int j = 0; j < BW; j++) {
			cin >> Black[i][j];
			dat_Black[Black[i][j]]++;
		}
	}
	int B=0;
	for (int i = 0; i < 100001; i++) {
		if (dat_Apart[i] > 0 && dat_Black[i] > 0) {
			B += dat_Apart[i];
		}
	}
	cout << B << '\n';
	cout << cntA - B;

	return 0;
}