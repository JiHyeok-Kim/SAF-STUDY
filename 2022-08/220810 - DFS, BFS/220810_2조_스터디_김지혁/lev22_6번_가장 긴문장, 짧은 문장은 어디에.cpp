#include <iostream>
#include <string>
using namespace std;

int main()
{
	string arr[4];
	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}

	int max = -9999;
	int maxWho;
	int min = 99999;
	int minWho;
	for (int i = 0; i < 4; i++) {
		int len = arr[i].length();
		if (len > max) { max = len; maxWho = i; }
		if (len < min) { min = len; minWho = i; }
	}
	cout << "긴문장:" << maxWho << "\n";
	cout << "짧은문장:" << minWho;

	return 0;
}