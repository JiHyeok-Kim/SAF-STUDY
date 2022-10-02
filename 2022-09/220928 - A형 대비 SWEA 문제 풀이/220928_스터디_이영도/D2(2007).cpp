// 패턴 마디의 길이 
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

int main() {
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		string inp;
		char f, tmp[10];
		int cnt = 0, ret, itmp;

		cin >> inp;
		f = inp[0];
		
		for (int i = 1; i < 11; i++) {
			itmp = 0;
			cnt++;
			tmp[i - 1] = inp[i - 1];
			if (inp[i] == f) {
				for (int j = 1; j < cnt+1; j++) {
					if (tmp[j - 1] == inp[cnt + (j - 1)]) itmp++;
				}
				if ((cnt) == itmp) {
					ret = cnt;
					break;
				}
			}
		}

		cout << "#" << tc + 1 << " " << ret << endl;
	}

	return 0;
}