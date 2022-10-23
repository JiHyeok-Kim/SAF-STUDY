// 숫자 만들기
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef struct {
	int add, sub, mul, div;
}str;
str oper;
str tmp;
int N, num[13], Max = -21e8, Min = 21e8;

void dfs(int lev, int n) {
	if (lev == N) {

		if (n > Max) Max = n;
		if (n < Min) Min = n;

		return;
	}

	for (int i = 0; i < 4; i++) {
		// operator empty
		if (tmp.add == 0 && i == 0 ||
			tmp.sub == 0 && i == 1 ||
			tmp.mul == 0 && i == 2 ||
			tmp.div == 0 && i == 3) continue;

		if (i == 0) { // add
			tmp.add--;
			dfs(lev + 1, n + num[lev]);
			tmp.add++;
		}
		else if (i == 1) { // sub
			tmp.sub--;
			dfs(lev + 1, n - num[lev]);
			tmp.sub++;
		}
		else if (i == 2) { // mul
			tmp.mul--;
			dfs(lev + 1, n * num[lev]);
			tmp.mul++;
		}
		else if (i == 3) { // div
			tmp.div--;
			dfs(lev + 1, n / num[lev]);
			tmp.div++;
		}

	}

}

void init() {
	N = 0;
	Max = -21e8;
	Min = 21e8;
	memset(num, 0, 13);
}

int main() {
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) { // test case
		init(); // initialization

		cin >> N;
		
		int a, s, m, d; // inp operator
		cin >> a >> s >> m >> d;
		oper = { a, s, m, d };

		for (int i = 0; i < N; i++) { // inp num
			cin >> num[i];
		}
		
		tmp = oper; // temp
		dfs(1, num[0]); // call func

		int ret = Max - Min;
		cout << "#" << tc + 1 << " " << ret << endl;
	}

	return 0;
}