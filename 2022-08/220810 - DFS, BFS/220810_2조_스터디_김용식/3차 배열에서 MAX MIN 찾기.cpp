#include <iostream>
using namespace std;
int main(){
	int arr[2][2] = {{2,4},{1,5}};
	int arr2[2][2] = {{2,3},{3,6}};
	int arr3[2][2] = {{7,3},{1,5}};

	int n;
	cin >> n;
	int max = 0;
	int max2 = 0;
	int max3 = 0;
	int min = 2e8;
	int min2 = 2e8;
	int min3 = 2e8;
	if (n == 0) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if (arr[i][j] > max) {
					max = arr[i][j];
				}
				if (arr[i][j] < min) {
					min = arr[i][j];
				}
			}
		}
		cout << "MAX=" << max << "\n";
		cout << "MIN=" << min;
	}else if (n == 1) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if (arr2[i][j] > max2) {
					max2 = arr2[i][j];
				}
				if (arr2[i][j] < min2) {
					min2 = arr2[i][j];
				}
			}
		}
		cout << "MAX=" << max2 << "\n";
		cout << "MIN=" << min2;
	}else if (n == 2) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if (arr3[i][j] > max3) {
					max3 = arr3[i][j];
				}
				if (arr3[i][j] < min3) {
					min3 = arr3[i][j];
				}
			}
		}
		cout << "MAX=" << max3 << "\n";
		cout << "MIN=" << min3;
	}



	return 0;
}