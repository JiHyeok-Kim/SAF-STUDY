#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;


bool cmp(string a, string b) {
	if (a.length() == b.length())
		return a < b;
	else {
		return a.length() < b.length();
	}
}

int N, T;
vector<string> input;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);

	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> N;
		for (int a = 0; a < N; ++a) {
			string tmp;
			cin >> tmp;
			input.push_back(tmp);
		}

		sort(input.begin(), input.end(), cmp);
		
		cout << "#" << t << "\n";
		string tmp = "";
		for (int a = 0; a < N; ++a) {
			if (tmp != input[a]) {
				cout << input[a] << "\n";
				tmp = input[a];
			}
		}
		input.clear();

	}
	
	return 0;
}
