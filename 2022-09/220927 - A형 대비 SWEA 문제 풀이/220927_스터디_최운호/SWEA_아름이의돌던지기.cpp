#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;
		int minVal = 21e8;
		int dat[100001] = { 0 };
		for (int i = 0; i < n; i++) {
			int dist;
			cin >> dist;
			dat[abs(dist)]++;
			minVal = min(abs(dist), minVal);
		}
		cout << "#" << t << " " << minVal << " " << dat[minVal] << '\n';
	}
	return 0;
}