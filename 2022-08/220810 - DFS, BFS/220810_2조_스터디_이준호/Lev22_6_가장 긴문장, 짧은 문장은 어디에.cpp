#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int max = -999;
	int maxid;
	int min = 999;
	int minid;

	for (int i = 0; i < 4; i++) {
		cin >> str;
		int a = str.size();
		if (max < a) {
			max = a;
			maxid = i;
		}
		if (min > a) {
			min = a;
			minid = i;
		}
	}

	cout << "긴문장:" << maxid << endl;
	cout << "짧은문장:" << minid;


	return 0;
}