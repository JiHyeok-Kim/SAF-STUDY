// ½Ã°£ °³³ä
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

// global
string str1, str2;
int H, M, S, curSec = 0, tarSec = 0, retSec = 0;

void parsing() { // parsing func 
	H = stoi(str1.substr(0, 2));
	M = stoi(str1.substr(3, 2));
	S = stoi(str1.substr(6, 2));
	curSec = (S)+(M * 60) + (H * 3600);

	H = stoi(str2.substr(0, 2));
	M = stoi(str2.substr(3, 2));
	S = stoi(str2.substr(6, 2));
	tarSec = (S)+(M * 60) + (H * 3600);
}

void compare() { // compare func
	if (curSec < tarSec) {
		retSec = tarSec - curSec;
	}
	else {
		retSec = ((24 * 3600) + tarSec) - curSec;
	}

	H = retSec / 3600;
	retSec = retSec % 3600;
	M = retSec / 60;
	S = retSec % 60;
}

void init() { // initialization func
	H = M = S = curSec = tarSec = retSec = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		init(); // init func call
		cin >> str1 >> str2;

		parsing(); // parsing func call (1)

		compare(); // compare func call

		printf("#%d %02d:%02d:%02d\n", tc + 1, H, M, S);
	}

	return 0;
}