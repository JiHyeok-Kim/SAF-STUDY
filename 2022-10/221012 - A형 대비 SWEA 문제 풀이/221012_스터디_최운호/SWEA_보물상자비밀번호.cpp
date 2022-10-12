#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int numCnt;

string pwd;

unordered_map<int, int> um;
vector<int> v;

void getPW() {
	int idx = 0;

	for (int i = 0; i <= N - numCnt; i+= numCnt) {
		string val = pwd.substr(i, numCnt);
		int temp = stoi(val, NULL, 16);
		if (um.count(temp) != 0) continue;
		um[temp] = 1;
		v.push_back(temp);
	}
}

void shift() {
	int len = pwd.size();
	char last = pwd[len - 1];

	for (int i = len - 2; i >= 0; i--) {
		pwd[i + 1] = pwd[i];
	}
	pwd[0] = last;

	return;
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> N >> K;

		numCnt = N / 4;
		
		cin >> pwd;

		for (int i = 0; i < numCnt; i++) {
			getPW();
			shift();
		}
		sort(v.begin(), v.end(), greater<>());

		cout << "#" << t << " " << v[K - 1] << '\n';

		v.clear();
		um.clear();
	}

	return 0;
}