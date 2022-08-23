#include <iostream>
using namespace std;
struct burak {
	int index;
	int value;
};
int burakNum, lastNum;
int Arr[1000001] = {0};
int sumSum[1000001] = {0};
	int main() {
	cin >> burakNum >> lastNum;

	for (int i = 0; i < burakNum; i++) {
		int idx, num;
		cin >> idx >> num;
		Arr[idx] = num;
	}
	
	sumSum[0] = Arr[0];
	for (int i = 1; i <= lastNum; i++) {
		sumSum[i] += sumSum[i - 1] + Arr[i];
	}

	int find;
	cin >> find;
	for(int i=0; i<find; i++){
		int a, b;
		cin >> a >> b;
		cout<< sumSum[b] - sumSum[a-1]<<'\n';
		
	}


	return 0;
}