#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<string, int> um;
unordered_map<char, int> um1;
int N, K;
vector<int> ansList;

long long getNum(string str) {
	long long ans = 0;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		long long mult16 = 1;
		for (int j = 0; j < len - 1 - i; j++) mult16 *= 16;
		ans += um1[str[i]] * mult16;
	}
	return ans;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	um1['0'] = 0;
	um1['1'] = 1;
	um1['2'] = 2;
	um1['3'] = 3;
	um1['4'] = 4;
	um1['5'] = 5;
	um1['6'] = 6;
	um1['7'] = 7;
	um1['8'] = 8;
	um1['9'] = 9;
	um1['A'] = 10;
	um1['B'] = 11;
	um1['C'] = 12;
	um1['D'] = 13;
	um1['E'] = 14;
	um1['F'] = 15;
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		string list1;
		um.clear();
		ansList.clear();
		cin >> N >> K;
		cin >> list1;
		list1 += list1;
		for (int i = 0; i < N; i++) {
			string temp = "";
			for (int j = 0; j < (N / 4); j++) {
				temp += list1[i + j];
			}
			if (um[temp] == 0) {
				um[temp] = 1;
				int temp1 = getNum(temp);
				ansList.push_back(temp1);
			}
		}
		sort(ansList.begin(), ansList.end(), greater<int>());
		cout << "#" << t << " " << ansList[K-1]<< "\n";
	}
	return 0;
}