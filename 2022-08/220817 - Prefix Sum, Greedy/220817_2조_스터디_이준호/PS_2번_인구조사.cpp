#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int bunho, popul;
int arr[100001];
int hap[100001];
int q, s, e;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> bunho >> popul;
		arr[bunho] = popul;
	}

	hap[0] = arr[0];
	for (int i = 1; i <= m; i++) {
		hap[i] = hap[i - 1] + arr[i];
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> s >> e;
		cout << hap[e] - hap[s - 1] << "\n";
	}


	return 0;
}