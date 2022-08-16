#include <iostream>
#include <vector>
using namespace std;

int idx, width;
int sum;
int Arr[100001];

int getSum(int index) {
	int sum = 0;
	for (int i = 0; i < width; i++) {
		sum += Arr[i];
	}
	return sum;
}

int main() {
	int tc;
	int a, b;
	cin >> tc;
	for (int j = 0; j < tc; j++) {
	
		cin >> idx >> width;

		for (int i = 0; i < idx; i++) {
			cin>>Arr[i];
		}
		
		sum = getSum(0);

	    int max = -5465488;

		for (int i = 0; i <= idx - width; i++) {
			if (sum > max) {
				max = sum;
				a = i;
				b = i + width-1;
			}
			if (i == idx - width)break;

			
			sum += Arr[i + width];
			sum -= Arr[i];
		}
		cout << '#'<<j+1<<" "<< a<<" "<<b<<" "<<max<<endl;
	}







	return 0;
}