#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> water;

int main() {
	long long N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		water.push_back(temp);
	}

	sort(water.begin(), water.end());

	long long st=0;
	long long la=water.size()-1;
	long long sum = 0;
	long long sum2 = 0;
	long long realx=water[st], realy = water[la];
	sum = water[st] + water[la];
	while (st < la) {
		if (sum == 0) {
			/*cout << water[st] << " " << water[la];*/
			break;
		}

		if (abs(water[st]) > abs(water[la])) {
			st++;
		}
		else {
			la--;
		}
		sum2 = water[st] + water[la];
		if (st == la) break;
		if (abs(sum) > abs(sum2) ) {
			sum = sum2;
			realx = water[st];
			realy = water[la];
		}
		
		
	}
	cout << realx << " " << realy;

	return 0;
}