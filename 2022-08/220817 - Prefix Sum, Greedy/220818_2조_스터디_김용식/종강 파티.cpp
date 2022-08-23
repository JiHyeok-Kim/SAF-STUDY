#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> six;
vector<int> one;


int main() {
	
	int num, market;
	cin >> num >> market;
	
	for (int i = 0; i < market; i++) {
		int mass, single;
		cin >> mass >> single;
		six.push_back(mass);
		one.push_back(single);
	}

	//작은 것 끼리 정렬완료.
	sort(six.begin(), six.end());
	sort(one.begin(), one.end());
	
	
	int result = 0;
	int n1 = num / 6;
	int n2 = num % 6;
	

	if (one[0] * 6 < six[0]) {
		result = one[0] * num;
		cout << result;
		return 0;
	}
	result = six[0]*n1;

	if (one[0] * n2 <= six[0]) {
		result += one[0] * n2;
	}
	else {
		result += six[0];
	}
	
	
	cout<<result;

	return 0;
}