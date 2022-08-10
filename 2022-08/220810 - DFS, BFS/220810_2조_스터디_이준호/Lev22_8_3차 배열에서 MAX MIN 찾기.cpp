#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> arr(5);

int main() {


	arr[0] = { 2,4,1,5 };
	arr[1] = { 2,3,3,6 };
	arr[2] = { 7,3,1,5 };

	int a;
	cin >> a;

	int max = -999;
	int min = 999;

	for (int x = 0; x < 4; x++) {
		if (max < arr[a][x]) {
			max = arr[a][x];
		}
		if (min > arr[a][x]) {
			min = arr[a][x];
		}
	}


	cout << "MAX=" << max << endl;
	cout << "MIN=" << min << endl;

	return 0;
}