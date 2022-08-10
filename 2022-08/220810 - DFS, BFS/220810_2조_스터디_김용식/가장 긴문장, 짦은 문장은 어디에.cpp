#include <iostream>
#include <string>
using namespace std;
int main() {
	string arr;
	int min = 2e8;
	int max = 0;
	int maxarray, minarray;
	for (int i = 0; i < 4; i++) {
		cin >> arr;	
		if (arr.length() > max) {
			max = arr.length();
			maxarray = i;
		}
		if (min>arr.length())
		{
			min = arr.length();
			minarray = i;
		}
	}
	cout << "긴문장:" << maxarray << endl;
	cout << "짧은문장:" << minarray;


	return 0;
}