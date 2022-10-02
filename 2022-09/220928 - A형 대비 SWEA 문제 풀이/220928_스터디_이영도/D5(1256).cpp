// [S/W 문제해결 응용] 6일차 - K번째 접미어
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

string inp;
vector<string> vec;

void func(int K) {
	while (1) {
		vec.push_back(inp);
		if (inp.size() == 1) break;
		string temp = inp.substr(1, inp.size() - 1);
		inp = temp;
	}

	sort(vec.begin(), vec.end());
}

int main() {
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int K;
		vec.clear();

		cin >> K;
		cin >> inp;

		func(K);

		cout << "#" << tc + 1 << " ";
		cout << vec[K - 1] << endl;
	}

	return 0;
}